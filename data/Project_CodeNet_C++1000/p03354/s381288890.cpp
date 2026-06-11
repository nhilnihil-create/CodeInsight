#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 100010;
int a[N], vis[N], n, m;
vector<int> adj[N];
vector<ii> comp;

void dfs (int u) {
  vis[u] = 1;
  comp.push_back({u, a[u]});
  for (int v : adj[u]) if (!vis[v]) dfs(v);
}

int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    dfs(i);
    set<int> v;
    for (const auto& p : comp) v.insert(p.second);
    for (const auto& p : comp) ans += v.count(p.first);
    comp.clear();
  }
  printf("%d\n", ans);
}

