#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 3010, mod = 1e9 + 7;
int dp[maxn][maxn], n;
string s;

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;

    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            (dp[i - 1][j] += dp[i - 1][j - 1]) %= mod;
        for (int j = 1; j <= i; j++)
            dp[i][j] = (s[i - 2] == '<' ? dp[i - 1][j - 1]
                                        : dp[i - 1][n] - dp[i - 1][j - 1] + mod) %
                       mod;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        (ans += dp[n][i]) %= mod;

    cout << ans;

    return 0;
}