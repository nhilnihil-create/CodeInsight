#include<bits/stdc++.h>
using namespace std;

struct UF {
  vector<int> par, siz;
  UF(int n): par(n), siz(n,1) {
  	for (int i = 0; i < n; i++) par[i] = i;
  }
  int find(int x) {
  	return par[x] == x ? x: par[x] = find(par[x]);
  }
  bool marge(int x, int y) {
  	x = find(x);
    y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x,y);
    siz[x] += siz[y];
    par[y] = par[x];
    return true;
  }
  bool same(int x, int y) {
  	return find(x) == find(y);
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
  	cin >> v[i];
    v[i]--;
  }
  UF uf(n);
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    uf.marge(v[a[i]], v[b[i]]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (uf.same(i, v[i])) ans++;
  }
  cout << ans << endl;
}
