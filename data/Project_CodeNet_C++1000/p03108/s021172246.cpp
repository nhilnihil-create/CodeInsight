#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

struct UnionFind {
  vector<int> data;
  void init(int n) { data.assign(n, -1); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x), y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  int size(int x) { return -data[root(x)]; }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  UnionFind uf;
  uf.init(n);
  ll res = 1ll * n * (n - 1) / 2;
  vector<ll> ans(m);
  for (int i = m - 1; i >= 0; --i) {
    ans[i] = res;
    if (!uf.same(a[i], b[i])) {
      res -= 1ll * uf.size(a[i]) * uf.size(b[i]);
      uf.unite(a[i], b[i]);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}