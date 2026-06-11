#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
const int MAXN = 2E5;
int c[MAXN + 1];
int pre[MAXN + 1];
int dp[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dp[0] = dp[1] = 1;
    pre[c[1]] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (c[i] != c[i - 1])
        {
            dp[i] = (dp[i] + pre[c[i]]) % MOD;
            pre[c[i]] = (pre[c[i]] + dp[i - 1]) % MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
