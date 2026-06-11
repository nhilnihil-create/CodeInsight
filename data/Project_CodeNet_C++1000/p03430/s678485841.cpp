#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[310];
int dp[310][310][310];

int main ()
{
//    freopen ("file.in", "r", stdin);

    fgets (str + 1, 310, stdin);

    int n = strlen (str + 1) - 1, k;
    scanf ("%d", &k);

    int ma = 1;

    for (int lg = 1; lg <= n; ++lg)
        for (int i = 1; i + lg - 1 <= n; ++i)
            for (int h = 0; h <= k; ++h)
            {
                int j = i + lg - 1;

                if (i == j) dp[i][j][h] = 1;
                else
                {
                    dp[i][j][h] = max (max (dp[i + 1][j][h], dp[i][j - 1][h]), dp[i + 1][j - 1][h] + 2 * (str[i] == str[j]));

                    if (h > 0)
                        dp[i][j][h] = max (dp[i][j][h], dp[i + 1][j - 1][h - 1] + 2);

                    ma = max (ma, dp[i][j][h]);
                }
            }

    printf ("%d\n", ma);

    return 0;
}
