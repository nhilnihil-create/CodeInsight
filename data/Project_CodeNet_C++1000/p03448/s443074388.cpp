#include <stdio.h>
int main(void)
{
    int a, b, c, x, ans = 0;
    int i, j, k;
    scanf("%d %d %d %d", &a, &b, &c, &x);

    for (i = 0; i < a+1; i++)
    {
        for (j = 0; j < b+1; j++)
        {
            for (k = 0; k < c+1; k++)
            {
                if(500*i + 100*j + 50*k == x)
                {
                    ans++;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
