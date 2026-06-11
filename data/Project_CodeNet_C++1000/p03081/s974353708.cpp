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

ll n, q;

// diel = 1, dier = 2, survive = 0
ll die(string& ts, string& ds, string& s, ll pos) {
  rep(i, q) {
    if (pos < 0)
      return 1;
    else if (pos >= n)
      return 2;
    if (s[pos] == ts[i]) {
      if (ds[i] == 'L')
        pos--;
      else
        pos++;
    }
  }
  if (pos < 0)
    return 1;
  else if (pos >= n)
    return 2;
  return 0;
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  string s;
  cin >> n >> q >> s;
  string ts, ds;
  rep(i, q) {
    char t, d;
    cin >> t >> d;
    ts += t, ds += d;
  }

  ll ans = n;

  // chk diel
  ll l = -1, r = n;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    if (die(ts, ds, s, m) == 1)
      l = m;
    else
      r = m;
  }
  ans -= l + 1;

  // chk dier
  l = -1, r = n;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    if (die(ts, ds, s, m) == 2)
      r = m;
    else
      l = m;
  }
  ans -= n - r;

  cout << ans << endl;

  return 0;
}
