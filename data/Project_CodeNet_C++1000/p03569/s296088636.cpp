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

int main() {
  string s;
  cin >> s;

  string swox = "";
  ll n = (ll)s.size();
  vll xs;
  ll cnt = 0;
  rep(i, n) {
    if (s[i] != 'x') {
      swox += s[i];
      xs.push_back(cnt);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  xs.push_back(cnt);

  ll n2 = (ll)swox.size();
  rep(i, n2 / 2) {
    if (swox[i] != swox[n2 - 1 - i]) {
      puts("-1");
      return 0;
    }
  }

  ll n3 = (ll)xs.size();
  ll ans = 0;
  rep(i, n3 / 2) ans += abs(xs[i] - xs[n3-1-i]);

  cout << ans << endl;

  return 0;
}
