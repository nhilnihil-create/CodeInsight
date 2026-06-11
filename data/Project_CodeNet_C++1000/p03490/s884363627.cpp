#include <algorithm>
#include <bitset>
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
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;

// int getidx(int x, int n) { return x + n; }
bool can(vl& xs, ll x) {
  vector<bool> dp(40001, false);
  dp[20000] = true;
  for (auto& dx : xs) {
    vector<bool> ndp(40001, false);
    rep(i, 40001) {
      if (dp[i]) {
        if (i - dx >= 0) ndp[i - dx] = true;
        if (i + dx < 40001) ndp[i + dx] = true;
      }
    }
    dp = ndp;
  }
  return dp[20000 + x];
}

int main() {
  //
  string s;
  cin >> s;
  int n = s.size();
  ll X, Y;
  cin >> X >> Y;
  bool xmove = true;
  bool first = true;
  vl dx, dy;
  ll cnt = 0;
  rep(i, s.size()) {
    if (s[i] == 'F') {
      cnt++;
    } else {
      if (xmove) {
        if (first) {
          first = false;
          X -= cnt;
        } else {
          dx.push_back(cnt);
        }
      } else {
        dy.push_back(cnt);
      }
      xmove = !xmove;
      cnt = 0;
    }
  }
  if (cnt > 0) {
    if (xmove) {
      if (first) {
        X -= cnt;
      } else {
        dx.push_back(cnt);
      }
    } else {
      dy.push_back(cnt);
    }
  }
  if (can(dx, X) && can(dy, Y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
