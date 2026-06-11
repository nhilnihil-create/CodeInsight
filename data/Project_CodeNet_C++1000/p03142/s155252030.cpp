#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
using LL = long long;

mt19937 rng( (int)chrono::steady_clock::now().time_since_epoch().count() );

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  #ifdef FourLeafClover
  freopen("input", "r", stdin);
  #endif // FourLeafClover

  int n, m; cin >> n >> m;
  vector<vector<int> > gr(n);
  vector<int> deg(n);
  for (int i = 0; i < n + m - 1; ++i) {
    int u, v; cin >> u >> v; --u; --v;
    gr[u].emplace_back(v);
    ++deg[v];
  }

  queue<int> q;
  for (int u = 0; u < n; ++u) if (!deg[u]) q.emplace(u);
  vector<int> par(n, -1);
  while (sz(q) ) {
    int u = q.front(); q.pop();
    for (int v : gr[u]) {
      --deg[v];
      if (!deg[v]) {
        par[v] = u;
        q.emplace(v);
      }
    }
  }

  for (auto &i : par) cout << i + 1 << '\n';

  return 0;
}
