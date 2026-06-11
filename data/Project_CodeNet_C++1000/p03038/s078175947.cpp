// 2020-07-15 21:44:03
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  ll n, m;
  cin >> n >> m;
  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    mp[a]++;
  }
  rep(i, m) {
    ll b, c;
    cin >> b >> c;
    mp[c] += b;
  }
  ll ans = 0;
  for(auto it = mp.rbegin(); it != mp.rend(); it++) {
    if(n <= 0) break;
    ll a, b;
    tie(a, b) = *it;
    debug(a, b);
    ans += a * min(n, b);
    n -= min(n, b);
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}