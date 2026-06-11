#include <bits/stdc++.h>
using namespace std;
#define Graph vector<vector<pair<int, int>>>
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

vector<int> color;
int nv;
void dfs(const Graph &g, int v, int c) {
  color[v] = c;
  for(auto np : g[v]) {
    nv = np.first;
    if(color[nv] == -1) {
      if(np.second % 2 == 0) dfs(g, nv, c);
      else dfs(g, nv, 1-c);
    }
  }
}
int main() {
  int N, a, b, d;cin >> N;
  Graph g(N);
  pair<int, int> p;
  rep(i, N-1) {
    cin >> a >> b >> d;
    p = make_pair(b-1, d);
    g[a-1].push_back(p);
    p = make_pair(a-1, d);
    g[b-1].push_back(p);
  }
  color.assign(N, -1);
  dfs(g, 0, 0);
  for(auto x : color) cout << x << endl;
}