#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
vector<vector<int>> g, dp;

void dfs(int x, int par) {
  for (auto v : g[x]) {
    if (v == par) continue;
    dfs(v, x);
    dp[x][0] = dp[x][0] * ((dp[v][1] + dp[v][0]) % M) % M;
    dp[x][1] = dp[x][1] * dp[v][0] % M;
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  g.resize(n);
  dp.assign(n, vector<int> (2, 1));
  
  if (n == 1) {
    cout << 2 << '\n';
    return 0;
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v; 
    --u; --v;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0, 0);
  cout << (dp[0][0] + dp[0][1]) % M << '\n';
}
