#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 1 && j == 1)
            {
                dp[i][j] = 1;
            }
            else if (v[i - 1][j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (dp[i][j] >= mod)
                {
                    dp[i][j] -= mod;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][m] << '\n';
}
