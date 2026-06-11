#include<stdio.h>
int main()
{
    int n,A,x;

    scanf("%d %d",&n, &A);

    if(n < 500)
    {
        if(n <= A)
            printf("Yes\n");
        else
            printf("No\n");
    }

    else if(n >= 500)
    {
        x = n % 500;
        if(x <= A)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

