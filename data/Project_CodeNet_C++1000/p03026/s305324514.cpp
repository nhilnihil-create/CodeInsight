#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> g[n + 1];
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> a(n);
  int tot = 0;
  rep(i, n) cin >> a[i], tot += a[i];

  sort(a.rbegin(), a.rend());
  tot -= a[0];

  int ans[n + 1] = {0};
  int l = 0;
  function<void(int, int)> dfs = [&](int u, int p) {
    ans[u] = a[l++];
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(v, u);
    }
  };

  dfs(1, 0);
  cout << tot << endl;
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
