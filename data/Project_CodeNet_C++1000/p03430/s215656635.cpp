#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
ll MOD = 1e9+7;
int main()
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    int dp[n+1][n+1][k+1];
    for(int i = 0; i <= n; i++)
    {
      for(int j = 0; j <= n; j++)
      {
        for(int x = 0; x <= k; x++) dp[i][j][x] = 0;
      }
    }
  
    for(int i = 0; i < n; i++)
    {
        dp[i][i][k] = 1;
        if(i+1 < n && s[i] == s[i+1]) dp[i][i+1][k] = 2;
        else dp[i][i+1][k] = 1;
        if(k) dp[i][i+1][k-1] = 2;
    }

    for(int i = 0; i < n; i++)
    {
        for(int l = 0; l+i < n; l++)
        {
            int r = l+i;
            for(int x = 0; x <= k; x++)
            {
                if(l > 0) dp[l-1][r][x] = max(dp[l-1][r][x], dp[l][r][x]);
                if(r+1 < n) dp[l][r+1][x] = max(dp[l][r+1][x], dp[l][r][x]);
                if(l > 0 && r+1 < n)
                {
                    if(s[l-1] == s[r+1]) dp[l-1][r+1][x] = max(dp[l-1][r+1][x], dp[l][r][x] + 2);
                    if(x) dp[l-1][r+1][x-1] = max(dp[l-1][r+1][x-1], dp[l][r][x] + 2);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++)
    {
        ans = max(ans, dp[0][n-1][i]);
    }
    cout << ans << endl;
}
