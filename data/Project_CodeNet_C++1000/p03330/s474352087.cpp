#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, C; cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> D[i][j];
    }
  }
  vector<vector<int>> count(3, vector<int>(C));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int c; cin >> c;
      count[(i + j) % 3][c-1]++;
    }
  }

  int ans = 1 << 30;
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      if (i == j) continue;
      for (int k = 0; k < C; k++) {
        if (i == k || j == k) continue;
        int res = 0;
        for (int c = 0; c < C; c++) {
          res += D[c][i] * count[0][c];
          res += D[c][j] * count[1][c];
          res += D[c][k] * count[2][c];
        }
        ans = min(ans, res);
      }
    }
  }
  cout << ans << "\n";
}