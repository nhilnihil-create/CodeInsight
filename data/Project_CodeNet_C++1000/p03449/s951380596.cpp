#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n)), b(2, vector<int>(n));
  rep(i, 2) rep(j, n) cin >> a[i][j];

  b[0][0] = a[0][0];
  for (int i = 1; i < n; i++) b[0][i] = b[0][i - 1] + a[0][i];

  b[1][n - 1] = a[1][n - 1];
  for (int i = n - 2; i >= 0; i--) b[1][i] = b[1][i + 1] + a[1][i];

  int maxcandy = 0;
  rep(i, n) { maxcandy = max(maxcandy, b[0][i] + b[1][i]); }
  cout << maxcandy << endl;
  return 0;
}
