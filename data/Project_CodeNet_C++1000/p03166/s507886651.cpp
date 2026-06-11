#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 10;

int n, m;
vector<int> g[maxN];
int vis[maxN];
int dp[maxN];
stack<int> s;
vector<int> ver;

void dfs(int u) {
  s.push(u);
  vis[u] = 1;
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  ver.push_back(u);
  s.pop();
}

int main(){
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  int ans = 0;
  for (int i = 0; i < ver.size(); ++i) {
    int u = ver[i];
    for (auto v : g[u]) {
      dp[u] = max(dp[u], dp[v] + 1);
    }
    ans = max(ans, dp[u]);
  }
  cout << ans;
return 0;
}
