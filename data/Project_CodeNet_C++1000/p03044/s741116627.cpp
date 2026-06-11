#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  queue<int> q;
  q.push(0);
  vector<int> col(n, -1);
  col[0] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto a : g[v]) {
      if (col[a.first] != -1) continue;
      if (a.second % 2 == 0) {
        col[a.first] = col[v];
      }
      else {
        col[a.first] = 1 - col[v];
      }
      q.push(a.first);
    }
  }
  rep(i, n) cout << col[i] << endl;
  return 0;
}
