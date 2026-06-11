#include <bits/stdc++.h>
using namespace std;
const int maxn = 3005;
using ll = long long;

const ll mod = 1e9 + 7;

ll dp[maxn][maxn];

ll pref[maxn];

int main()
{
  string s;
  int n;
  cin >> n >> s;
  
  dp[1][1] = 1;
  for(int i = 2; i <= n; i++)
  {
    pref[0] = 0;
    for(int j = 1 ; j <= n; j++)
    {
      pref[j] = pref[j - 1] + dp[i - 1][j];
      pref[j] %= mod;
    }

    for(int j = 1; j <= i; j++)
    {
      if(s[i - 2] == '>')
        dp[i][j] = (pref[n] - pref[j - 1] + mod);
      else
        dp[i][j] = pref[j - 1];
      dp[i][j] %= mod;
    }

  }

  ll ans = 0;
  for(int i = 1; i <= n; i++)
    ans = (ans + dp[n][i]) % mod;

  cout << ans << endl;
  return 0;
}