#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i,n-1) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  vector<vector<ll>> dp(n, vector<ll>(2, 0));
  auto dfs = [&](auto& f, int p, int u)->void{
    dp[u][0] = dp[u][1] = 1;
    for (auto v : g[u]) {
      if (v == p) continue;
      f(f, u, v);
      (dp[u][0] *= (dp[v][0] + dp[v][1])) %= mod;
      (dp[u][1] *= dp[v][0]) %= mod;
    }
  };

  dfs(dfs, -1, 0);
  cout << (dp[0][0] + dp[0][1]) % mod << endl;
  return 0;
}
