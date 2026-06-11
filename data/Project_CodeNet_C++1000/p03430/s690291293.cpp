/**
 *    author:  tourist
 *    created: 24.02.2018 15:11:31       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 303;

int f[N][N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int) s.length();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      for (int p = 0; p <= k; p++) {
        if (i == j) {
          f[i][j][p] = 1;
          continue;
        }
        if (i + 1 == j) {
          f[i][j][p] = (s[i] == s[j] || p > 0) ? 2 : 1;
          continue;
        }
        f[i][j][p] = max(f[i + 1][j][p], f[i][j - 1][p]);
        if (s[i] == s[j]) {
          f[i][j][p] = max(f[i][j][p], f[i + 1][j - 1][p] + 2);
        }
        if (p > 0) {
          f[i][j][p] = max(f[i][j][p], f[i + 1][j - 1][p - 1] + 2);
        }
      }
    }
  }
  cout << f[0][n - 1][k] << endl;
  return 0;
}
