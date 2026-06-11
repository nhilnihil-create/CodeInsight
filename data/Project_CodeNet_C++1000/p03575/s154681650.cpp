#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
vector<int> g[55];
int st[55], ft[55], low[55];
int vis[55];
int counter = 1;
int ans = 0;
void dfs(int u, int p = -1) {
  vis[u] = 1;
  st[u] = low[u] = counter++;
  st[u] = counter++;
  for (int v : g[u]) {
    if (v == p)
      continue;
    if (!vis[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > st[u]) {
        ans++;
      }
    } else {
      low[u] = min(low[u], st[v]);
    }
  }
  ft[u] = counter++;
}
int main() {
  IOS;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  cout << ans << endl;
}
