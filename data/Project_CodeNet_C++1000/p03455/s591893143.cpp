#include <stdio.h>

int main(void)
{
    int a, b, ans;
    scanf("%d %d", &a, &b);
    ans = a * b;
    if (ans%2 == 0)
    {
        puts("Even");
    }
    else
    {
        puts("Odd");
    }
    return 0;
}