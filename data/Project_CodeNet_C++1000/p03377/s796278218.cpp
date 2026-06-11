#include<stdio.h>
int main()
{
    int a,b,x;
    scanf("%d%d%d",&a,&b,&x);
    if(((a<x)&&(x-a)<=b)||x==a)
    printf("YES\n");
    else
        printf("NO\n");
}