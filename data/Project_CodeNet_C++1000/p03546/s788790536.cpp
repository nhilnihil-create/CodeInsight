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
  ll h, w;
  cin >> h >> w;
  vector<vl> c(10, vl(10)), g(h, vl(w));
  rep(i, 10) rep(j, 10) cin >> c[i][j];
  rep(i, h) rep(j, w) cin >> g[i][j];
  rep(k, 10) rep(i, 10) rep(j, 10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
  ll ans = 0;
  rep(i, h) rep(j, w) {
    ll k = g[i][j];
    if(abs(k) != 1) ans += c[k][1];
  }
  cout << ans << endl;
}