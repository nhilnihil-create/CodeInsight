#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uf.unite(x, y);
    }
    vector<int> A(n, 0);
    int ans = 0;
    rep(i, n) {
        int x = uf.find(i);
        if (A[x] == 0) ans++;
        A[x]++;
    }
    cout << ans << endl;
    return 0;
}