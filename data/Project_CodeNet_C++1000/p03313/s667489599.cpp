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
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  vector<int> a((1 << n));
  rep(i, (1 << n)) cin >> a[i];

  vector<pair<int, int>> dp((1 << n));
  rep(S, (1 << n)) {
    dp[S] = {S, -1};
    rep(i, n) {
      if (S >> i & 1) {
        int T = S & ~(1 << i);
        if (a[dp[T].first] > a[dp[S].first]) {
          dp[S] = {dp[T].first, dp[S].first};
          if (a[dp[T].second] > a[dp[S].second] && dp[S].first != dp[T].second) {
            dp[S].second = dp[T].second;
          }
        }
        else if (dp[S].second == -1) {
          dp[S].second = dp[T].first;
        }
        else if (a[dp[T].first] > a[dp[S].second] && dp[S].first != dp[T].first) {
          dp[S].second = dp[T].first;
        }
      }
    }
  }
  int ans = 0;
  FOR(S, 1, (1 << n)) {
    chmax(ans, a[dp[S].first] + a[dp[S].second]);
    //cout << dp[S].first << ' ' << dp[S].second << '\n';
    cout << ans << '\n';
  }


  




  
  return 0;
}
