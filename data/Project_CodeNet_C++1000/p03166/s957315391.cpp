#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    g[x].emplace_back(y);
  }

  vector<int> dp(n, 0);

  auto dfs = [&](auto& f, int u, int p)->void{
    if (dp[u]) return ;
    for (auto v : g[u]) {
      if (v == p) continue;
      f(f, v, u);
      dp[u] = max(dp[u], dp[v] + 1);
    }
  };

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!dp[i]) dfs(dfs, i, -1);
    res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}
