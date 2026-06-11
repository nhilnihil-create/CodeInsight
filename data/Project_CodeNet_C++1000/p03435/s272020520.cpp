#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  vector<vector<int>> c(4, vector<int>(4));
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) cin >> c[i][j];
  }

  for (int a1 = 0; a1 <= 100; a1++) {
    for (int a2 = 0; a2 <= 100; a2++) {
      for (int a3 = 0; a3 <= 100; a3++) {
        int b1 = c[1][1] - a1;
        int b2 = c[2][2] - a2;
        int b3 = c[3][3] - a3;

        if (a2 + b1 == c[2][1] && a3 + b1 == c[3][1] && a1 + b2 == c[1][2] &&
            a3 + b2 == c[3][2] && a1 + b3 == c[1][3] && a2 + b3 == c[2][3]) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
}
