#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll MOD = 1000000007;
vector<vector<int>> g;
vector<vector<ll>> dp;

void dfs(int pre, int crt)
{
  dp[crt].resize(2);
  dp[crt][0] = dp[crt][1] = 1;
  for (int nxt : g[crt])
  {
    if (nxt == pre)
      continue;
    dfs(crt, nxt);
    dp[crt][0] = dp[crt][0] * (dp[nxt][0] + dp[nxt][1]) % MOD;
    dp[crt][1] = dp[crt][1] * dp[nxt][0] % MOD;
  }
}

int main()
{
  int n;
  cin >> n;
  g.resize(n);
  rep(i, n - 1)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dp.resize(n);
  dfs(-1, 0);
  cout << (dp[0][0] + dp[0][1]) % MOD << endl;
  return 0;
}