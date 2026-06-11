#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  vll p(n); REP(i, n) cin >> p[i];

  vvll dp(n+1, vll(n+1, HIGHINF));
  dp[0][0] = 0;
  REP(i, n) {
    REP(j, n+1) {
      if (dp[i][j] >= HIGHINF) continue;
      if (p[i] > j) {
        // p[i]を右にずらさない
        chmin(dp[i+1][p[i]], dp[i][j]);
        // p[i]を右にずらす
        chmin(dp[i+1][j], dp[i][j] + a);
      } else {
        // p[i]を左にずらさないといけない
        chmin(dp[i+1][j], dp[i][j] + b);
      }
    }
  }

  ll ans = HIGHINF;
  REP(i, n+1) chmin(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
