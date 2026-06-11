#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define trav(var, container) for(auto& var: container)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)x.size()
using namespace std;
using namespace __gnu_pbds;
using ld = long double; 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64(x*C); }
};


ll my_ceil(ll a, ll b) {
  if(a <= 0) return 0;
  ll x = a + b - 1;
  if(x >= b) return x / b;
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  ll h;
  cin >> n >> h;
  vector<pair<ll, ll>> v(n);
  ll maxA = LLONG_MIN;
  for(auto& i: v) {
    cin >> i.first >> i.second;
    maxA = max(maxA, i.first);
  }
  sort(all(v), [](auto& a, auto& b) {
    return a.second > b.second;
  });
  ll ans = LLONG_MAX;
  ll cum_sum = 0;
  ans = my_ceil(h, maxA);
  int cnt = 0;
  for(auto& i: v) {
    // ll a = i.first;
    ll b = i.second;
    cum_sum += b;
    ++cnt;
    // cout << my_ceil(h - cum_sum, maxA) + cnt << " ";
    ans = min(my_ceil(h - cum_sum, maxA) + cnt, ans);
  }
  cout << ans;
  return 0;
}