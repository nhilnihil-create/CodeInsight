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
  ll a, b, q;
  cin >> a >> b >> q;
  vl s(a), t(b);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];
  sort(all(s));
  sort(all(t));
  rep(_, q) {
    ll x;
    cin >> x;
    vl u(2), v(2);
    u[0] = upper_bound(all(s), x) - s.begin() - 1;
    v[0] = upper_bound(all(t), x) - t.begin() - 1;
    u[1] = lower_bound(all(s), x) - s.begin();
    v[1] = lower_bound(all(t), x) - t.begin();
    ll ans = 1e18;
    rep(i, 2) rep(j, 2) {
      if(u[i] < 0 || v[j] < 0) continue;
      ll d1 = s[u[i]];
      ll d2 = t[v[j]];
      ll now;
      if(x <= d1 && x <= d2 || x > d1 && x > d2)
        now = max(abs(x - d1), abs(x - d2));
      else
        now = 2 * min(abs(x - d1), abs(x - d2)) + max(abs(x - d1), abs(x - d2));
      ans = min(ans, now);
    }
    cout << ans << '\n';
  }
}