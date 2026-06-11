#include <iostream>

using namespace std;

int table[501][501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M, Q;
  cin >> N >> M >> Q;

  int l, r;
  for (int i = 0; i < M; i++) {
    cin >> l >> r;
    table[l][r]++;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      table[i][j] += table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
    }
  }
  int p, q;
  for (int i = 0; i < Q; i++) {
    cin >> p >> q;

    const int ans =
        table[q][q] - table[p - 1][q] - table[q][p - 1] + table[p - 1][p - 1];
    cout << ans << endl;
  }

  return 0;
}
