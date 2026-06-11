#include <bits/stdc++.h>
using namespace std;

template<typename T> class Weighted_UnionFind {
public:
  int n;
  vector<int> par, nrank;
  vector<T> wd;
  Weighted_UnionFind(int node_size) : n(node_size), par(n), nrank(n, 0), wd(n, 0) {
    iota(par.begin(), par.end(), 0);
  }
  int root(int x) {
    if (par.at(x) == x) {
      return x;
    } else {
      int parent = root(par.at(x));
      wd.at(x) += wd.at(par.at(x));
      return par.at(x) = parent;
    }
  }
  T weight(int x) {
    root(x);
    return wd.at(x);
  }
  void unit(int x, int y, T w) {
    w += weight(x), w -= weight(y);
    x = par.at(x), y = par.at(y);
    if (x == y) return;
    if (nrank.at(x) < nrank.at(y)) {
      swap(x, y);
      w = -w;
    }
    nrank.at(x) += (nrank.at(x) == nrank.at(y));
    par.at(y) = x;
    wd.at(y) = w;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  T diff(int x, int y) {
    return weight(y) - weight(x);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  Weighted_UnionFind<int> WU(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    if (WU.same(a, b)) {
      if (WU.diff(a, b) != c) return cout << "No" << "\n", 0;
    } else {
      WU.unit(a, b, c);
    }
  }
  cout << "Yes" << "\n";
}