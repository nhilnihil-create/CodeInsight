#include<bits/stdc++.h>
#define F first
#define S second
#define REP(i, a, b, c) for(int i = a; i <= b; i+=c)
#define pb push_back
#define int long long int
#define MOD 1000000007
using namespace std;

int a[105];

int solve(int n, int k) {
  int dp[n + 5][k + 5];
  for (int j = 0; j <= k; j++)
  {
    dp[1][j] = (j > a[1]) ? 0 : 1;
  }
  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      if (j == 0)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = (MOD + dp[i][j - 1] + dp[i - 1][j] - ((j - a[i] - 1 >= 0) ? dp[i - 1][j - a[i] - 1] : 0)) % MOD;

    }
  }
  return dp[n][k];
}

int32_t main()
{
  ios :: sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  for (int i9 = 1; i9 <= t; i9++)
  {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    cout << solve(n, k);
  }
}

