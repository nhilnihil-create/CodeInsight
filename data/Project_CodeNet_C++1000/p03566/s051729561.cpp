#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  vl t(n), l(n + 2), r(n + 2), v(n + 2);
  ll now = 0;
  rep(i, n) {
    cin >> t[i];
    l[i] = now;
    now += t[i];
    r[i] = now;
  }
  l[n] = now;
  r[n] = now;
  v[n] = l[n + 1] = r[n + 1] = v[n + 1] = 0;
  rep(i, n) cin >> v[i];
  ll m = now * 2 + 1;
  vd s(m, 1e18);
  rep(i, m) rep(j, n + 2) {
    double now;
    if(i < 2 * l[j])
      now = -double(i) / 2.0 + double(l[j]) + double(v[j]);
    else if(i > 2 * r[j])
      now = double(i) / 2.0 - double(r[j]) + double(v[j]);
    else
      now = double(v[j]);
    s[i] = min(s[i], now);
  }
  double ans = 0;
  rep(i, m - 1) ans += (s[i] + s[i + 1]) / 4.0;
  printf("%.15f\n", ans);
}