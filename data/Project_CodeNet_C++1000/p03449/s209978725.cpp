#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep(i, 2) rep(j, n) cin >> a[i][j];
  int ans = 0;
  rep(k, n) {
    int i = 0;
    int c = 0;
    rep(j, n) {
      c += a[i][j];
      if (j == k) c += a[++i][j];
    }
    ans = max(ans, c);
  }
  cout << ans << endl;
  return 0;
}