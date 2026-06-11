#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
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

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;

const ll INF = 1LL << 32;

int main() {
  ll n, K;
  cin >> n >> K;
  vll xs(n);
  vll ys(n);

  for (ll i = 0; i < n; i++) {
    cin >> xs[i] >> ys[i];
  }

  ll ans = LONG_LONG_MAX;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      for (ll k = 0; k < n; k++) {
        for (ll l = 0; l < n; l++) {
          bool cond = xs[i] < xs[j] && ys[k] < ys[l];
          if (!cond) continue;
          ll num = 0;
          for (ll t = 0; t < n; t++) {
            bool inside = xs[i] <= xs[t] && xs[j] >= xs[t] && ys[k] <= ys[t] &&
                          ys[l] >= ys[t];
            if(inside){
              num++;
            }
          }  // t
          if(num >= K) {
            ll tmp = (xs[j] - xs[i])*(ys[l] - ys[k]);
            chmin(ans, tmp);
          }
        } // l
      } //k
    } //j
  } //i

  cout << ans << endl;

  return 0;
}
