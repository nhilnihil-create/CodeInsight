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
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

const ll INF = 1LL << 50;

static const long long mod = 1000000007;

ll n, a, b, c;
vll ls;

ll dfs(ll d, ll an, ll bn, ll cn, ll ac, ll bc, ll cc){
  if (d == n) {
    if (ac == 0 || bc == 0 || cc == 0) return INF;
    return abs(a - an) + abs(b - bn) + abs(c - cn) + 10*(ac-1) + 10*(bc-1) + 10*(cc-1);
  }
  ll ans = INF;
  chmin(ans, dfs(d + 1, an + ls[d], bn, cn, ac+1, bc, cc));
  chmin(ans, dfs(d + 1, an, bn + ls[d], cn, ac, bc+1, cc));
  chmin(ans, dfs(d + 1, an, bn, cn + ls[d], ac, bc, cc+1));
  chmin(ans, dfs(d + 1, an, bn, cn, ac, bc, cc));
  return ans;
}

int main() {
  cin >> n >> a >> b >> c;
  ls.resize(n);
  rep(i, n) cin >> ls[i];

  ll ans = dfs(0, 0, 0, 0, 0, 0, 0);
  cout << ans << endl;

  return 0;
}
