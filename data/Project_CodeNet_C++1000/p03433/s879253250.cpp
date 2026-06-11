#include<stdio.h>

int main()
{
    int N, A, remainder;

    scanf("%d %d", &N, &A);

    remainder = N % 500;

    if(remainder <= A)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
