#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int dp[305][305][305];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  string s;
  int k;
  cin >> s >> k;

  int n = s.length();
  rep(i, n) {
    dp[i][i][k] = 1;
    if (i < n - 1) {
      dp[i][i + 1][k] = 1 + (s[i] == s[i + 1]);
      if (k) dp[i][i + 1][k - 1] = 2;
    }
  }
  FOR(i, 1, n + 1) {
    rep(l, n - i + 1) {
      int r = l + i - 1;
      rep(c, k + 1) {
        if (l) chmax(dp[l - 1][r][c], dp[l][r][c]);
        if (r < n - 1) chmax(dp[l][r + 1][c], dp[l][r][c]);
        if (l && r < n - 1) {
          if (dp[l][r][k]) {
            chmax(dp[l - 1][r + 1][c], dp[l][r][c] + 2 * (s[l - 1] == s[r + 1]));
          }
          else {
            chmax(dp[l - 1][r + 1][c], 1 + (s[l - 1] == s[r + 1]));
          }
          if (c) chmax(dp[l - 1][r + 1][c - 1], dp[l][r][c] + 2);
        }
      }
    }
  }
  int ans = 0;
  rep(i, k + 1) chmax(ans, dp[0][n - 1][i]);
  cout << ans << '\n';


  
  return 0;
}