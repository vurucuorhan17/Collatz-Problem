#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
    int gelenSayi = 0;
    do
    {
        gelenSayi = okunanSayi();
    }
    while (gelenSayi<=0);
    
    
    collatz(gelenSayi);
    return 0;
}

int okunanSayi()
{
    int sayi;
    printf("Sayiyi girin: ");
    scanf("%d",&sayi);
    return sayi;
}

void collatz(int sayi)
{
   
    pid_t child_id = fork();

    if(child_id!=0)
    {
        wait(&child_id);
        kill(getpid(),SIGKILL);
    }
    else
    {
        printf("%d\n",sayi);
        if(sayi==1)
            return;
        if(sayi%2==0)
        {
            sayi = sayi / 2;
        }
        else if(sayi%2==1)
        {
            sayi = 3*sayi+1;
        }
        collatz(sayi);
    }
    

}   