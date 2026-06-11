#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, q; cin >> n >> q;
  string s; cin >> s;
  V<char> t(q), d(q); REP(i, q) cin >> t[i] >> d[i];
  // 左側の落ちる判定
  ll l_l=0, l_r=n;
  while (l_l < l_r) {
    ll mid = (l_l + l_r) / 2;
    ll tmp = mid;
    REP(i, q) {
      if (tmp<0 || tmp>=n) break;
      if (s[tmp] == t[i]) {
        if (d[i] == 'L') tmp--;
        else tmp++;
      }
    }
    if (tmp < 0) l_l = mid+1;
    else l_r = mid;
  }
  // 右側の落ちる判定
  ll r_l=0, r_r=n;
  while (r_l < r_r) {
    ll mid = (r_l + r_r) / 2;
    ll tmp = mid;
    REP(i, q) {
      if (tmp<0 || tmp>=n) break;
      if (s[tmp] == t[i]) {
        if (d[i] == 'L') tmp--;
        else tmp++;
      }
    }
    if (tmp >= n) r_r = mid;
    else r_l = mid+1;
  }
  cout << r_r - l_r << endl;
  return 0;
}
