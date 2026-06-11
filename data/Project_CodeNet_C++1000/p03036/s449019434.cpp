#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cal(int r, int d, int x)
{
    return r * x - d;
}

int main(void)
{
    int ans = 0;

    int r, d, x;
    scanf("%d%d%d", &r, &d, &x);

    rep(i, 10)
    {
        int tmp = cal(r, d, x);
        printf("%d\n", tmp);
        x = tmp;
    }

    return 0;
}