#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;
const ll Inf = 4000000000000000000ll;

int n, a, b;
ll dp[Maxn][Maxn];

int main()
{
    fill((ll*)dp, (ll*)dp + Maxn * Maxn, Inf);
    scanf("%d %d %d", &n, &a, &b);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int num; scanf("%d", &num);
        for (int j = 0; j <= n; j++) if (dp[i][j] < Inf)
            if (j > num) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + ll(b));
            else {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + ll(a));
                dp[i + 1][num] = min(dp[i + 1][num], dp[i][j]);
            }
    }
    ll res = Inf;
    for (int i = 0; i <= n; i++)
        res = min(res, dp[n][i]);
    printf("%lld\n", res);
    return 0;
}
