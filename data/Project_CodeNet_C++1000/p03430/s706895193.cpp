#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 320
using namespace std;

char a[N];
int f[N][N][N];

int main(void)
{
    int n, k;
    int i, j, t, o;

    scanf("%s %d", a + 1, &k);
    n = strlen(a + 1);
    if(n == 1)
    {
        printf("1\n");

        return 0;
    }
    if(n == 2)
    {
        printf("%d\n", 1 + (a[1] == a[2] || k));

        return 0;
    }

    for(i = 1, o = 0; i <= n; i ++)
        for(j = n; j > i; j --)
            for(t = 0; t <= k; t ++)
            {
                f[i][j][t] = max(f[i - 1][j][t], f[i][j + 1][t]);
                if(a[i] == a[j])
                    f[i][j][t] = max(f[i][j][t], f[i - 1][j + 1][t] + 1);
                else if(t)
                    f[i][j][t] = max(f[i][j][t], f[i - 1][j + 1][t - 1] + 1);

                // printf("left %d, right %d, change %d : %d\n", i, j, t, f[i][j][t]);
                o = max(o, f[i][j][t] * 2 + (i < j - 1));
            }
    printf("%d\n", o);

    return 0;
}
