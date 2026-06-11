#include <iostream>

using namespace std;

const int MAX = 1e5;

class UnionFind {
public:
  long long score;

  UnionFind(int n) {
    for (int i = 0; i < n; i++) {
      data[i] = i;
      size[i] = 1;
    }

    score = (long long)n * (n - 1) / 2;
  }

  // O(log N)
  int root(int x) {
    int rx = data[x];
    while(rx != data[rx]) {
      rx = data[rx];
    }
    return rx;
  }

  // O(log N)
  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    if (size[rx] < size[ry]) swap(rx, ry);
    data[ry] = rx;
    score -= size[rx] * size[ry];
    size[rx] += size[ry];
    size[ry] = 0;
  }

private:
  int data[MAX];
  int size[MAX];
};

int main() {
  int N, M; cin >> N >> M;
  int A[MAX], B[MAX];
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  long long res[MAX];
  UnionFind uf(N);

  // O(MlogN)
  // Calculate in inverse order
  for (int i = M - 1; i >= 0; i--) {    
    res[i] = uf.score; // The score is when the bridge is collapsed, ie before unite
    uf.unite(A[i], B[i]);
  }

  for (int i = 0; i < M; i++) {
    cout << res[i] << endl;
  }
}