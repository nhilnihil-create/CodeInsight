#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  vector<vector<int>> zahyo(N, vector<int>(3));
  for (int i = 0; i < N; i++) {
    int x, y, h;
    cin >> x >> y >> h;
    zahyo[i][0] = x;
    zahyo[i][1] = y;
    zahyo[i][2] = h;
  }
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      int height = 0;
      for (int t = 0; t < N; t++) {
        if (height == 0 && zahyo[t][2] != 0) {
          height = zahyo[t][2] + abs(zahyo[t][0] - i) + abs(zahyo[t][1] - j);
          break;
        }
      }
      for (int t = 0; t < N; t++) {
        int takasa = zahyo[t][2] + abs(zahyo[t][0] - i) + abs(zahyo[t][1] - j);
        if (zahyo[t][2] != 0) {
          if (takasa != height) {
            // cout << i << " " << j <<  " " << t  <<endl;
            break;
          }
        } else {
          if (takasa < height) {
            break;
          }
        }
        if (t == N - 1) {
          cout << i << " " << j << " " << height << endl;
          return 0;
        }
      }
    }
  }
}
