#include <bits/stdc++.h>

using namespace std;
const int N = 3005;
const int MOD = 1e9+7;
int dp[N][N];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    dp[1][1] = 1;
    for (int i = 2; i<=n; i++)
    {
        if (s[i-2] == '<')
        {
            for (int j = 1; j<=i; j++)
                dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%MOD;
        }
        else
        {
            for (int j = i-1; j>=1; j--)
                dp[i][j] = (dp[i-1][j]+dp[i][j+1])%MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i<=n; i++)
        ans = (ans+dp[n][i])%MOD;
    cout << ans;
}
