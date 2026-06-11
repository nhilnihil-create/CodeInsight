#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector <vector <ll>> dp(n, vector <ll> (n));
    for (int i=0; i<n; ++i)
        dp[0][i] = 1;

    for (int i=1; i<n; ++i)
    {
        for (int j=0; j<=i; ++j)
        {
            if (s[i-1] == '<' && j != 0)
                dp[i][j] = dp[i-1][j-1];
            if (s[i-1] == '>' && j != 0)
                dp[i][j] = dp[i-1][n-1] - dp[i-1][j-1] + mod;
            else if (s[i-1] == '>')
                dp[i][j] = dp[i-1][n-1];
        }
        for (int j=1; j<n; ++j)
        {
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][n-1];

    return 0;
}