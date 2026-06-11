#include<stdio.h>

int main()
{
    int n,a,num;

    scanf("%d %d",&n,&a);

    if(n<500)
    {
        if(a>=n)
            printf("Yes");
        else
            printf("No");
    }

    else
    {
        num = n%500;

        if(a>=num)
            printf("Yes");
        else
            printf("No");
    }

    return 0;
}
