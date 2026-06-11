#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

map<ll, ll> primeFactor(ll n) {
  map<ll, ll> res;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if(n != 1) res[n] = 1;
  return res;
}

int main() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  rep2(i, 2, n + 1) {
    auto pf = primeFactor(i);
    for(auto v : pf) mp[v.first] += v.second;
  }
  ll ans = 0;
  ll n2 = 0, n4 = 0, n14 = 0, n24 = 0, n74 = 0;
  for(auto v : mp) {
    ll m = v.second;
    if(m >= 2) n2++;
    if(m >= 4) n4++;
    if(m >= 14) n14++;
    if(m >= 24) n24++;
    if(m >= 74) n74++;
  }
  ans += max(0LL, n24 * (n2 - 1));
  ans += max(0LL, n4 * (n4 - 1) / 2 * (n2 - 2));
  ans += max(0LL, n14 * (n4 - 1));
  ans += n74;
  cout << ans << endl;
}