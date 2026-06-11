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

vector<vl> s(2);

ll f(ll x, ll sm, ll t) {
  ll res;
  if(sm == 0) {
    auto it = lower_bound(all(s[t]), x);
    res = it == s[t].end() ? *(it - 1) : *it;
  } else {
    auto it = upper_bound(all(s[t]), x);
    res = it == s[t].begin() ? *it : *(it - 1);
  }
  return res;
}

int main() {
  ll a, b, q;
  cin >> a >> b >> q;
  s[0].resize(a), s[1].resize(b);
  rep(i, a) cin >> s[0][i];
  rep(i, b) cin >> s[1][i];
  sort(all(s[0]));
  sort(all(s[1]));
  rep(_, q) {
    ll x;
    cin >> x;
    ll ans = 1e18;
    rep(k, 2) {
      rep(i, 2) rep(j, 2) {
        ll s1 = f(x, i, 0);
        ll t1 = f(s1, j, 1);
        ll now = abs(x - s1) + abs(s1 - t1);
        ans = min(ans, now);
      }
      swap(s[0], s[1]);
    }
    cout << ans << '\n';
  }
}