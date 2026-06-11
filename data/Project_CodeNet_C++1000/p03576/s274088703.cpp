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

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n, k;
  cin >> n >> k;

  vll xs(n), ys(n);
  rep(i, n) cin >> xs[i] >> ys[i];

  map<ll, ll> rmpx, rmpy;

  {  // cx
    map<ll, ll> mp;
    rep(i, n) mp[xs[i]] = 0;
    ll j = 1;
    for (auto& x : mp) x.second = j++;
    rep(i, n) {
      ll tx = mp[xs[i]];
      rmpx[tx] = xs[i];
      xs[i] = mp[xs[i]];
    }
  }
  {  // cy
    map<ll, ll> mp;
    rep(i, n) mp[ys[i]] = 0;
    ll j = 1;
    for (auto& x : mp) x.second = j++;
    rep(i, n) {
      ll ty = mp[ys[i]];
      rmpy[ty] = ys[i];
      ys[i] = mp[ys[i]];
    }
  }

  vvll csum(n + 1, vll(n + 1, 0));
  rep(i, n) csum[ys[i]][xs[i]]++;

  rep(i, n) rep(j, n) csum[i + 1][j + 1] +=
      csum[i][j + 1] + csum[i + 1][j] - csum[i][j];

  ll yaruo = LONG_LONG_MAX;
  repLRE(x1, 1, n - 1) repLRE(y1, 1, n - 1) repLRE(x2, x1 + 1, n)
      repLRE(y2, y1 + 1, n) {
    ll num = csum[y2][x2] - csum[y1 - 1][x2] - csum[y2][x1 - 1] +
             csum[y1 - 1][x1 - 1];
    if (num >= k) {
      ll tmp = (rmpx[x2] - rmpx[x1]) * (rmpy[y2] - rmpy[y1]);
      chmin(yaruo, tmp);
    }
  }

  cout << yaruo << endl;

  return 0;
}
