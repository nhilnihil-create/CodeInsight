#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W;
  cin >> H >> W;
  vector<vector<int>> C(10, vector<int>(10));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> C[i][j];
    }
  }
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int x;
      cin >> x;
      if (x == -1) continue;
      res += C[x][1];
    }
  }
  cout << res << '\n';
  return 0;
}
