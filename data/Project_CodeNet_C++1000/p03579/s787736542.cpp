#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
  vector<int> par, weight;
  UnionFind(int n) : par(n,-1), weight(n) {}
  void unite(int x, int y, int w = 0) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (par[x] > par[y]) swap(x, y), w = -w;
    par[x] += par[y];
    par[y] = x;
    return;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int find(int x) {
    if(par[x] < 0) return x;
    int r = find(par[x]);
    return par[x] = r;
  }
  int sizeOf(int x) { return -par[find(x)]; }
};

long n, m, a, b;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  UnionFind uf(n * 2);
  for(int i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    uf.unite(a, b + n);
    uf.unite(b, a + n);
  }
  if(uf.same(0, n)) {
    cout << (n * (n-1) >> 1) - m << endl;
  } else {
    int cnt = 0;
    for(int i = 0;i < n; ++i) {
      if(uf.same(0, i)) ++cnt;
    }
    cout << cnt * (n - cnt) - m;
  }
  return 0;
}