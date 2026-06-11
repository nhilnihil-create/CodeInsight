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

const ll mod = 1e9 + 7;

int main() {
  ll n, k;
  string s;
  cin >> n >> k >> s;

  s += "x";
  dqll as;
  ll sp = 0;
  rep(i, n) {
    if (s[i] != s[i + 1] || s[i + 1] == 'x') {
      ll sign = (s[i] == '0') ? -1 : 1;
      as.push_back(sign * (i - sp + 1));
      sp = i + 1;
    }
  }

  ll nas = as.size();

  ll ans = 0, sum = 0;
  ll cnt = 0;
  ll lp = 0, rp = 0;
  while (rp < nas) {
    if (as[rp] > 0) {
      sum += as[rp];
      rp++;
    } else {
      if (cnt < k) {
        sum -= as[rp];
        rp++;
        cnt++;
      } else {
        if (as[lp] > 0) {
          sum -= as[lp];
        } else {
          sum += as[lp];
          cnt--;
        }
        lp++;
      }
    }
    chmax(ans, sum);
  }  // while

  cout << ans << endl;

  return 0;
}
