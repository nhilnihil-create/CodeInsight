#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2 + 3, mxK = 1e5 + 3, MOD = 1e9 + 7;
int n, k, candies[mxN];
int dp[mxN][mxK], prefix[mxK];

int calc(int i)
{
    if (i < 0)
        return 0;
    return prefix[i];
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> candies[i];
    
    dp[0][0] = 1;
    for (int i = 0; i <= mxK; i++)
    {
        prefix[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int c = 0; c <= k; c++)
        {
            int ret = 0;
            // for (int use = 0; use <= candies[i]; use++)
            // {
            //     if (c - use >= 0)
            //     {
            //         ret += dp[i - 1][c - use];
            //         ret %= MOD;
            //     }
            // }

            ret = ((calc(c) - calc(max(c - candies[i], 0) - 1)) % MOD + MOD) % MOD;
            dp[i][c] = ret;
        }

        prefix[0] = dp[i][0];
        for (int a = 1; a <= k; a++)
        {
            prefix[a] = prefix[a - 1] + dp[i][a];
            prefix[a] %= MOD;
        }
    }

    cout << dp[n][k];
}