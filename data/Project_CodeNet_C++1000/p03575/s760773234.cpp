#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par;
  
  UnionFind(int N) : par(N) {
    for (int i = 0; i < N; i++) par.at(i) = i;
  }
  
  int root(int x) {
    if (par.at(x) == x) return x;
    return par.at(x) = root(par.at(x));
  }
  
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par.at(rx) = ry;
  }
  
  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    UnionFind tree(N);
    for (int j = 0; j < M; j++) {
      if (i != j) tree.unite(A.at(j), B.at(j));
    }
    for (int j = 0; j < N; j++) {
      if (!(tree.same(0, j))) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}