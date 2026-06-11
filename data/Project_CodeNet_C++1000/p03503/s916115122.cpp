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
  vector<vl> f(n, vl(10)), p(n, vl(11));
  rep(i, n) rep(j, 10) cin >> f[i][j];
  rep(i, n) rep(j, 11) cin >> p[i][j];
  ll ans = -1e18;
  rep2(i, 1, 1 << 10) {
    vb open(10, false);
    rep(j, 10) if(i >> j & 1) open[j] = true;
    ll now = 0;
    rep(j, n) {
      ll cnt = 0;
      rep(k, 10) if(f[j][k] && open[k]) cnt++;
      now += p[j][cnt];
    }
    ans = max(ans, now);
  }
  cout << ans << endl;
}