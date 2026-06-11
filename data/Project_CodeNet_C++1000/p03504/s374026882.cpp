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
  ll n, c;
  cin >> n >> c;
  const ll time = 101010LL;
  vvll arr(c, vll(time, 0));
  for (ll i = 0; i < n; i++) {
    ll s, t, ci;
    cin >> s >> t >> ci;
    s--;
    ci--;
    arr[ci][s]++;
    arr[ci][t]--;
  }


  for (ll i = 0; i < c; i++) {
    for (ll j = 1; j <= time; j++) {
      arr[i][j] += arr[i][j-1];
    }
  }

  for (ll i = 0; i < c; i++) {
    for (ll j = 0; j < time; j++) {
      if (arr[i][j] >= 1) arr[i][j] = 1;
    }
  }

  ll ans = 0;
  for (ll i = 0; i < time; i++) {
    ll cnt_i = 0;
    for (ll j = 0; j < c; j++) {
      cnt_i += arr[j][i];
    }  // j
    chmax(ans, cnt_i);
  }  // i

  cout << ans << endl;

  return 0;
}
