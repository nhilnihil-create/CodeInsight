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
  vl c(n), s(n), f(n);
  rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
  rep(i, n) {
    ll ans = 0;
    rep2(j, i, n - 1) ans = (max(ans, s[j]) + f[j] - 1) / f[j] * f[j] + c[j];
    cout << ans << '\n';
  }
}