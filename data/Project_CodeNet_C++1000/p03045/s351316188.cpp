#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n,m;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool union_(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

signed main() {
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m) {
    int x,y,z; cin >> x >> y >> z; x--;y--;
    uf.union_(x,y);
  }
  vector<bool> t(n);
  int ans = 0;
  rep(i,n) {
    int r = uf.root(i);
    if (t[r]) continue;
    ans++;
    t[r] = true;
  }

  cout << ans << endl;

}
