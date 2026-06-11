#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> f(n, vector<int>(10));
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, 0, n) rep(j, 0, 10) cin >> f[i][j];
  rep(i, 0, n) rep(j, 0, 11) cin >> p[i][j];

  ll ans = -(1 << 30);
  rep(b, 1, 1 << 10) {
    ll cc = 0;
    rep(i, 0, n) {
      int c = 0;
      rep(j, 0, 10) if ((b >> j & 1) && f[i][j]) c++;
      cc += p[i][c];
    }
    ans = max(ans, cc);
  }
  cout << ans << endl;

  return 0;
}
