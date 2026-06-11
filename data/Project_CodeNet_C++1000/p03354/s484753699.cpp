#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

struct UnionFind {
  vector<int> parent;

  UnionFind(int n) : parent(n) {
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int root(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = root(parent[x]);
  }

  void unite(int a, int b) {
    int ra = root(a);
    int rb = root(b);
    if (ra == rb) return;
    parent[ra] = parent[rb];
  }

  bool same(int a, int b) {
    return root(a) == root(b);
  }
};

// ====================================================================

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }

  UnionFind uni(n * 2);
  for (int i = 0; i < n; i++) uni.unite(v[i], i + n);
  // cout << uni.parent << endl;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uni.unite(a, b);
  }

  // 数字iが書かれている所は位置x+nにある
  // cout << uni.parent << endl;

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (uni.same(v[i], v[i] + n)) count++;
  }
  cout << count << endl;
  return 0;
}
