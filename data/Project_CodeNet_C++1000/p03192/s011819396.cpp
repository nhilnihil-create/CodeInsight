#include<stdio.h>
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=0)
    {
        if(x%10==2)
        i++;
        x/=10;
    }
    printf("%d\n",i);
    return 0;
}