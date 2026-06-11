#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int M = 100000;

int n, m, x[M], y[M], z[M];

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main() {
  cin >> n >> m;
  rep(i, m) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }
  UnionFind uf(n);
  rep(i, m) uf.unite(x[i], y[i]);
  set<int> st;
  rep(i, n) st.insert(uf.find(i));
  int ans = st.size();
  cout << ans << endl;
  return 0;
}