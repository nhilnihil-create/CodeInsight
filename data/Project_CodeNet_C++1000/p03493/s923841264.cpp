#include <cstdio>

int main()
{
    int a;
    scanf("%d", &a);
    int num = 0;
    if (a % 10 == 1)
    {
        num = num + 1;
    }
    
    if ((a / 10) % 10 == 1)
    {
        num = num + 1;
    }
    
    if (a / 100 == 1)
    {
        num = num + 1;
    }
    printf("%d", num);
    
}