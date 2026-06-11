#include <bits/stdc++.h>
using namespace std;

int dpTable[2][100];

void dp(vector<vector<int>>& a, int n) {
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) {
        continue;
      }
      dpTable[i][j] = a[i][j] +
        max(dpTable[max(i - 1, 0)][j], dpTable[i][max(j - 1, 0)]);
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
        dpTable[i][j] = 0;
    }
  }
  dpTable[0][0] = a[0][0];
  dp(a, n);
  cout << dpTable[1][n - 1] << endl;
}
