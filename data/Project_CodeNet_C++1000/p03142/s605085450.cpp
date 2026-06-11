#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, degin[N], par[N];
vector<int> des[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  m += n - 1;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    des[u].emplace_back(v);
    ++degin[v];
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (degin[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v: des[u]) {
      if (--degin[v] == 0) {
        par[v] = u;
        q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << par[i] << "\n";
  return 0;
}