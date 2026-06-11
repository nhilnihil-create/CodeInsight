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

int main() {
  ll n;
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    ll d;
    cin >> d;
    mp[d]++;
  }
  for(auto p : mp) {
    ll d = p.first;
    ll m = p.second;
    if(m >= 3 || d == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 0;
  rep(i, 1 << 12) {
    vl v = {0, 24};
    rep(j, 12) {
      ll k = j + 1;
      if(mp[k] == 0) continue;
      if(mp[k] == 2) {
        v.push_back(k);
        v.push_back(24 - k);
        continue;
      }
      if(i >> j & 1)
        v.push_back(k);
      else
        v.push_back(24 - k);
    }
    sort(all(v));
    ll now = 12;
    rep(j, v.size() - 1) now = min(now, v[j + 1] - v[j]);
    ans = max(ans, now);
  }
  cout << ans << endl;
}
