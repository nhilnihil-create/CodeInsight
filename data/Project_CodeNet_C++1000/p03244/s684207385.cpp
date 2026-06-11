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
  multiset<P> ev, ov;
  ev.insert({0, INF});
  ov.insert({0, INF});
  for (P p : em) ev.insert({p.second, p.first});
  for (P p : om) ov.insert({p.second, p.first});

  auto ite = ev.rbegin(), ito = ov.rbegin();
  ll e0c, e0v, e1c, e1v;
  tie(e0c, e0v) = *ite++;
  tie(e1c, e1v) = *ite;
  ll o0c, o0v, o1c, o1v;
  tie(o0c, o0v) = *ito++;
  tie(o1c, o1v) = *ito;

  ll ans;
  if (e0v != o0v) {
    ans = (n + 1) / 2 - e0c;
    ans += n / 2 - o0c;
  } else {
    ans = INF;
    ll tmp;
    tmp = (n + 1) / 2 - e0c;
    tmp += n / 2 - o1c;
    chmin(ans, tmp);
    tmp = (n + 1) / 2 - e1c;
    tmp += n / 2 - o0c;
    chmin(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
