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

  ll n;
  cin >> n;

  vll ts(n + 1), vs(n + 1);
  rep(i, n) cin >> ts[i];
  rep(i, n) cin >> vs[i];
  ts[n] = 0;
  vs[n] = 0;

  vll minv(2*20005, 400);
  ll sumt = 0;
  rep(i, n + 1) {
    ll stminv = 2*vs[i] + sumt;
    rep(j, sumt) { chmin(minv[j], stminv - j); }
    rep(j, 2*ts[i] + 1) { chmin(minv[j + sumt], 2*vs[i]); }
    sumt += 2*ts[i];
  }
  ll curv = 0;
  double ans = 0.0;
  repLRE(i, 1, sumt) {
    ll prev = curv;
    if (curv < minv[i])
      curv++;
    else if (curv > minv[i])
      curv--;
    ans += (curv + prev) / 2.0;
  }

  cout << ans/4.0 << endl;

  return 0;
}
