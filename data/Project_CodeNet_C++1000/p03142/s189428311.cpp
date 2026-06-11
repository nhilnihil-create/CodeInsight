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
  vector<int> deg(n, 0);
  rep(i,n + m - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b);
    deg[b]++;
  }
  int root = -1;
  for ( int i = 0; i < n; i++) if (!deg[i]) root = i;
  vector<int> par(n, 0);
  queue<int> que;
  que.push(root);
  par[root] = -1;
  while (!que.empty()) {
    int u = que.front(); que.pop();
    for (auto v : g[u]) {
      deg[v]--;
      if (deg[v] == 0) {
        que.push(v);
        par[v] = u;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << par[i] + 1 << endl;
  return 0;
}
