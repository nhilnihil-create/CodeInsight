#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
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

ll sumd(ll x) {
  ll ans = 0;
  while (x > 0) {
    ans += x%10;
    x/=10;
  }
  return ans;
}

int main() {
  ll k; cin >> k;
  ll ans = 1;
  ll d = 1;
  REP(i, k) {
    cout << ans << endl;
    if (1.0*(ans+d)/sumd(ans+d) > d) d *= 10;
    ans += d;
  }
  return 0;
}
