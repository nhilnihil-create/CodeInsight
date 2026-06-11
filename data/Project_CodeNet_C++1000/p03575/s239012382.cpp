#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

template <typename T>
class UnionFind {
 private:
  vector<T> parent;
  vector<T> group_size;

 public:
  UnionFind(T size_) : parent(size_), group_size(size_, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  void reset() {
    iota(parent.begin(), parent.end(), 0);
    fill(group_size.begin(), group_size.end(), 1);
  }
  
  T root(T x) { return parent[x] == x ? x : parent[x] = root(parent[x]); }

  void merge(T x, T y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    if (group_size[x] < group_size[y]) swap(x, y);
    group_size[x] += group_size[y];
    parent[y] = x;
  }

  bool same(T x, T y) { return root(x) == root(y); }
  T size(T x) { return group_size[root(x)]; }
};

int main() {
  int N, M, ans{};
  cin >> N >> M;
  vector<pair<int,int>> e(M);
  for (int i = 0; i != M; ++i) {
    cin >> e[i].first >> e[i].second;
  }

  UnionFind<int> u(N);
  for (int i = 0; i != M; ++i) {
    u.reset();
    for (int j = 0; j != M; ++j) {
      if (i == j) continue;
      u.merge(e[j].first-1, e[j].second-1);
    }
    if (u.size(0) < N) ++ans;
  }
  cout << ans << endl;
}
