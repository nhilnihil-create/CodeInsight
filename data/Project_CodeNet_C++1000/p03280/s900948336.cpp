#include<stdio.h>
int main()
{
    int a,b,s;
    scanf("%d%d",&a,&b);
    s=a*b;
    printf("%d\n",(s-(1*a+1*b)+1));
}