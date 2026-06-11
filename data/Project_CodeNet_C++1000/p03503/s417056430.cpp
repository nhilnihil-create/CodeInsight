#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  int n, ans = -1000000000;
  cin >> n;
  vector<int> shop(n, 0);
  rep(i, n) {
    rep(j, 10) {
      int x;
      cin >> x;
      shop[i] += pow(2, j) * x;
    }
  }
  int P[n][11];
  rep(i, n) rep(j, 11) cin >> P[i][j];
  for (int bit = 1; bit < (1 << 10); ++bit) {
    int res = 0;
    rep(i, n) {
      int tmp = bit & shop[i];
      int cnt = 0;
      rep(j, 10) {
        if (tmp & (1 << j)) cnt++;
      }
      res += P[i][cnt];
    }
    ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}
