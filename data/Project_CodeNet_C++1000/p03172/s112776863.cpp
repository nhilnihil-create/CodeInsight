#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int  dp[n + 1][k + 1];

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;



    const int mod = 1e9 + 7;
    for (int i = 1; i <= n; i++)
    {
        vector<int> prefixsum(k + 1);
        prefixsum[0] = dp[i - 1][0];

        for (int j = 1; j <= k; j++)
        {
            prefixsum[j] = (prefixsum[j - 1] + dp[i - 1][j]) % mod;
        }

        for (int j = 0; j <= k; j++)
        {
            if (j <= a[i])
                dp[i][j] = prefixsum[j];
            else
            {
                int h = j - a[i] - 1;
                dp[i][j] = (prefixsum[j] - prefixsum[h] + mod) % mod;
            }
        }
        prefixsum.clear();
    }
    cout << dp[n][k] << endl;
}