#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
using pis = pair<int, string>;
#define all(x) (x).begin(), (x).end()
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n, -1) {}

  //functions
  void init_tree() {
    for (int i = 0; i < d.size(); i++) {
      d[i] = -1;
    }
  }
  
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }

  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int size(int x) {
    return -d[find(x)];
  }

  int bls() {
    int ans = 0;
    for (int i = 0; i < d.size(); i++) if (d[i] < 0) ans++;
    return ans;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(15)

  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    if (!uf.same(x, y)) uf.unite(x, y);
  }
  cout << uf.bls() << endl;
}
