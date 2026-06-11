#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
ll d[100005];
int c[100005];
int vis[100005];
vector<pii> g[100005];
void dfs(int u) {
  vis[u] = 1;
  for (pii q : g[u]) {
    ll v = q.ff, w = q.ss;
    if (vis[v])
      continue;
    d[v] = d[u] + w;
    if (d[v] & 1)
      c[v] = 1;
    else
      c[v] = 0;
    dfs(v);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    cout << c[i] << endl;
}