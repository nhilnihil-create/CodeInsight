#include<stdio.h>

int main()
{
    int x;

    scanf("%d", &x);

    if (x<1200) printf("ABC");
    else if (1200<=x && x<2800) printf("ARC");
    else if (x>=2800) printf("AGC");

    return 0;
}