#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, ans, result;

int main() {
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep (i, 2) {
    rep (j, n) {
      cin >> a[i][j];
    }
  }
  rep (i, n) {
    result = 0;
    rep (j, n) {
      if (j <= i) result += a[0][j];
      if (i <= j) result += a[1][j];
    }
    ans = max(ans, result);
  }
  cout << ans << endl;
  return 0;
}
