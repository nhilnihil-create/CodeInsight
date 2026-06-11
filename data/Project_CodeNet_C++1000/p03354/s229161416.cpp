#include <bits/stdc++.h>
using namespace std;

struct UF {
  vector<int> p;
  int n;

  UF(int siz) {
    n = siz;
    p.resize(n, 0);
    for (int i = 0; i < n; i++) p[i] = i;
  }

  int parent(int x) {
    if (p[x] != x) p[x] = parent(p[x]);
    return p[x];
  }

  bool same(int x, int y) { return parent(x) == parent(y); }

  void unite(int x, int y) {
    x = parent(x), y = parent(y);
    p[x] = y;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  vector<int> x(m), y(m);
  UF uf(n);
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    x[i]--, y[i]--;
    uf.unite(x[i], y[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans += uf.parent(p[i]) == uf.parent(i);
  cout << ans << endl;
  return 0;
}
