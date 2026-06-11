#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
ll INF = 1LL << 60;

double f(double v, double left, double right, double t) {
  return min(v, min(t + left, -t + right));
}

double calc(double v, double t0, double t1, double left, double right) {
  // cout << t0 << ":" << t1 << ":" << left << ":" << right << endl;
  set<double> tlist;
  tlist.insert(t0);
  tlist.insert(t1);
  tlist.insert(v - left);
  tlist.insert(right - v);
  tlist.insert((right - left) / 2.0);
  double pt = -1, py;
  bool start = false;
  double ans = 0;
  for (auto& t : tlist) {
    if (!start) {
      if (t == t0) {
        start = true;
        pt = t;
        py = f(v, left, right, t);
      }
    } else {
      if (t <= t1) {
        ans += (py + f(v, left, right, t)) * (t - pt) / 2.0;
        py = f(v, left, right, t);
        // cout << t << ":" << py << "," << ans << endl;
        pt = t;
      } else {
        break;
      }
    }
  }
  return ans;
}

int main() {
  ll n;
  cin >> n;
  vl t(n), v(n), ts(n);
  rep(i, n) { cin >> t[i]; }
  ts[0] = t[0];
  REP(i, 1, n) { ts[i] = ts[i - 1] + t[i]; }
  rep(i, n) cin >> v[i];
  vl left(n), right(n);
  left[0] = 0;
  right[n - 1] = ts[n - 1];
  REP(i, 1, n) {
    if (v[i] >= v[i - 1]) {
      left[i] = min(left[i - 1], v[i - 1] - ts[i - 1]);
    } else {
      left[i] = left[i - 1];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] >= v[i + 1]) {
      right[i] = min(right[i + 1], v[i + 1] + ts[i]);
    } else {
      right[i] = right[i + 1];
    }
  }
  double ans = 0;
  rep(i, n) {
    ll t0 = 0;
    if (i > 0) t0 = ts[i - 1];
    ll t1 = ts[i];
    ans += calc(v[i], t0, t1, left[i], right[i]);
  }
  cout << setprecision(5) << fixed << ans << endl;

  return 0;
}
