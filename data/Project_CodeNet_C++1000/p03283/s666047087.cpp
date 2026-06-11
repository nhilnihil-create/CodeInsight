#include <iostream>

using namespace std;

int table[501][501];
int C[501][501];

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    table[l][r]++;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      C[i][j] = C[i][j - 1] + table[i][j];
    }
  }
  for (int i = 0; i < Q; i++) {
    int p, q;
    cin >> p >> q;
    int ans = 0;
    for (int j = p; j <= q; j++) {
      ans += C[j][q] - C[j][p - 1];
    }
    cout << ans << endl;
  }
  return 0;
}
