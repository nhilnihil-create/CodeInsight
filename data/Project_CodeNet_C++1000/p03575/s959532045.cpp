#include <iostream>

using namespace std;

const int MAX = 50;

class UnionFind {
public:
  // O(N)
  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      data[i] = i;
    }
    num_subtrees = n;
  }

  // O(N)
  int root(int x) {
    int rx = data[x];
    while(rx != data[rx]) {
      rx = data[rx];
    }
    return rx;
  }

  // O(N)
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    data[ry] = rx;
    num_subtrees--;
    return;
  }

  // O(1)
  bool complete() {
    return num_subtrees == 1;
  }

private:
  int data[MAX];
  int num_subtrees;
};

int main() {
  int N, M; cin >> N >> M;

  int a[MAX], b[MAX];
  for (int i = 0; i < M; i++) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  int ans = M;
  
  // O(N^3)
  // Choose which to omit
  for (int i = 0; i < M; i++) {
    UnionFind uf(N);
    for (int j = 0; j < M; j++) {
      if (i == j) continue;
      uf.unite(a[j], b[j]);
    }
    if (uf.complete()) {
      ans--;
    }
  }

  cout << ans << endl;
}