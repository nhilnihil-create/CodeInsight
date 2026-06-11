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

  vll as;
  ll now = 1;
  ll cnt = 0;
  rep(i, n) {
    if (s[i] - '0' != now) {
      as.push_back(cnt);
      cnt = 1;
      now = 1 - now;
    } else
      cnt++;
  }  // i
  if (cnt > 0) as.push_back(cnt);
  if (as.size() % 2 == 1) as.push_back(0);

  ll ans = 0;
  ll sum = 0;
  ll add = 2 * k + 1;

  ll left = 0;
  ll right = 0;
  for (ll i = 0; i < (ll)as.size(); i += 2) {
    ll nextleft = i;
    ll nextright = min(nextleft + add, (ll)as.size());
    while (left < nextleft) {
      sum -= as[left];
      left++;
    }
    while (right < nextright) {
      sum += as[right];
      right++;
    }
    chmax(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
