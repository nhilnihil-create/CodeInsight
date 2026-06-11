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

int main() {
  //
  ll n, k;
  cin >> n >> k;
  vl a(n), s(n);
  rep(i, n) cin >> a[i];
  s[0] = a[0];
  REP(i, 1, n) { s[i] = s[i - 1] + a[i]; }
  vl b;
  rep(i, n) {
    REP(j, -1, i) {
      if (j < 0) {
        b.push_back(s[i]);
      } else {
        b.push_back(s[i] - s[j]);
      }
    }
  }
  ll ans = 0;
  for (int i = 40; i >= 0; i--) {
    ll tmp = 1LL << i;
    ll cnt = 0;
    for (auto& y : b) {
      // cout << y << endl;
      if ((y & (ans + tmp)) == (ans + tmp)) cnt++;
    }
    if (cnt >= k) {
      // cout << tmp << ":" << cnt << endl;
      ans += tmp;
    }
  }
  cout << ans << endl;
  return 0;
}
