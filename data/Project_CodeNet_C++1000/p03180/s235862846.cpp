#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

static const long long mod = 1000000007;

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  vvll as(n, vll(n));
  rep(i, n) rep(j, n) cin >> as[i][j];

  vll pts(1 << n);
  vvll pats(n + 1);
  rep(s, 1 << n) {
    pats[__builtin_popcount(s)].push_back(s);
    rep(i, n) repLRE(j, i + 1, n - 1) {
      if ((s >> i) & (s >> j) & 1) pts[s] += as[i][j];
    }
  }

  vll dp(1 << n, 0);
  rep(i, n + 1) {
    rep(j, (ll)pats[i].size()) {
      ll s = pats[i][j];
      chmax(dp[s], pts[s]);
      for (ll t = s; t > 0; --t &= s) {
        chmax(dp[s], dp[s & t] + dp[s & ~t]);
      }
    }
  }

  cout << dp[(1 << n) - 1] << endl;

  return 0;
}
