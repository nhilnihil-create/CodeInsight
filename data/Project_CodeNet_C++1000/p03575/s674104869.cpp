#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;

struct UnionFind{
  vector<int> par;
  UnionFind(int N) : par(N) {
    rep(i,N) par[i] = i;
  }

  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) return;

    par[rx] = ry;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

int n, m;
int main() {
  cin >> n >> m;
  vector<P> edge(m);
  rep(i,m) {
    int a,b; cin >> a >> b;
    edge[i] = {a-1,b-1};
  }

  int ans = 0;
  rep(i,m) {
    UnionFind uf(n);
    int a = edge[i].first, b = edge[i].second;
    rep(j,m) {
      if (j == i) continue;
      uf.unite(edge[j].first, edge[j].second);
    }
    if (!uf.same(a,b)) ans++;
  }

  cout << ans << endl;
  return 0;
}