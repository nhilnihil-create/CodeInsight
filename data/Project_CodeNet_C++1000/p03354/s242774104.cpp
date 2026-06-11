#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct UnionFind {
  vector<int> par;

  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void merge(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
  }

  bool is_same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int N, M; cin >> N >> M;
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    int p; cin >> p; p--;
    P[i] = p;
  }

  UnionFind tree(N);
  for (int i = 0; i < M; i++) {
    int x, y; cin >> x >> y; x--; y--;
    tree.merge(x, y);
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int root = tree.root(P[i]);
    if (tree.is_same(root, i)) ans++;
  }

  cout << ans << endl;

}
