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

  map<ll, ll> em, om;
  rep(i, n) {
    ll a;
    cin >> a;
    if (i & 1)
      om[a]++;
    else
      em[a]++;
  }
  vP ev, ov;
  ev.push_back({0, INF});
  ov.push_back({0, INF});
  for (P p : em) ev.push_back({p.second, p.first});
  for (P p : om) ov.push_back({p.second, p.first});
  rSort(ev), rSort(ov);

  ll ans;
  if (ev[0].second != ov[0].second) {
    ans = (n + 1) / 2 - ev[0].first;
    ans += n / 2 - ov[0].first;
  } else {
    ans = INF;
    ll tmp;
    tmp = (n + 1) / 2 - ev[0].first;
    tmp += n / 2 - ov[1].first;
    chmin(ans, tmp);
    tmp = (n + 1) / 2 - ev[1].first;
    tmp += n / 2 - ov[0].first;
    chmin(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
