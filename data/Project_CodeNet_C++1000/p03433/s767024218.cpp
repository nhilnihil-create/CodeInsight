#include <stdio.h>

int main()
{
    int n, a;
    scanf("%d %d", &n, &a);
    if (n % 500 <= a)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
