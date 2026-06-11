#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, deg[100010], ans[100010];
vector<int> g[100010];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for(int i = 0; i < n - 1 + m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    ++deg[b];
  }

  int root;
  for(int i = 1; i <= n; ++i) if(deg[i] == 0) root = i;

  queue<int> q;
  q.push(root);
  while(q.size()) {
    int v = q.front(); q.pop();
    
    for(int nv : g[v]) {
      --deg[nv];
      if(deg[nv] == 0) {
        q.push(nv);
        ans[nv] = v;
      }
    }
  }
  for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
  return 0;
}