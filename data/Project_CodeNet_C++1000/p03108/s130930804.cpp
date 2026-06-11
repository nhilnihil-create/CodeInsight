#include <iomanip>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

vector<int> parent;
vector<int64_t> nodes;
int getParent(int x) {
  int y = x;
  while (y != parent[y]) {
    y = parent[y];
  }
  parent[x] = y;
  return y;
}

bool isSame(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  return (x == y);
}

bool unite(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x == y) return false;
  if (nodes[x] < nodes[y]) swap(x, y);
  parent[y] = x;
  nodes[x] += nodes[y];
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  int64_t N, M;
  cin >> N >> M;
  vector<int> A(M);
  vector<int> B(M);
  rep(i, M) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }

  parent.resize(N);
  nodes.resize(N, 1);
  rep(i, N) parent[i] = i;

  vector<int64_t> answer(M);
  answer[M - 1] = N * (N - 1) / 2;
  for (int i = M - 1; i > 0; --i) {
    if (isSame(A[i], B[i])) {
      answer[i - 1] = answer[i];
    } else {
      int a = getParent(A[i]);
      int b = getParent(B[i]);
      int64_t diff = nodes[a] * nodes[b];
      answer[i - 1] = answer[i] - diff;
      unite(A[i], B[i]);
    }
  }

  rep(i, M) { cout << answer[i] << endl; }
  return 0;
}
