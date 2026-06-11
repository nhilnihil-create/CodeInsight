#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep(i, 2) {
    rep(j, n) {
      cin >> a[i][j];
    }
  }
  int tot = a[1][n - 1];
  rep(i, n) {
    tot += a[0][i];
  }
  int ans = tot;
  for (int i = n - 1; i > 0; i--) {
    tot += a[1][i - 1] - a[0][i];
    ans = max(ans, tot);
  }
  cout << ans << endl;
  return 0;
}