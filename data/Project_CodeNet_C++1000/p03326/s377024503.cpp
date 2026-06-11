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
  ll n, m;
  cin >> n >> m;
  vl x(n), y(n), z(n);
  rep(i, n) cin >> x[i] >> y[i] >> z[i];
  ll ans = 0;
  rep(a, 2) rep(b, 2) rep(c, 2) {
    priority_queue<P> q;
    rep(i, n)
        q.push({x[i] * pow(-1, a) + y[i] * pow(-1, b) + z[i] * pow(-1, c), i});
    ll nx = 0, ny = 0, nz = 0;
    rep(_, m) {
      ll i = q.top().second;
      q.pop();
      nx += x[i];
      ny += y[i];
      nz += z[i];
    }
    ll now = abs(nx) + abs(ny) + abs(nz);
    ans = max(ans, now);
  }
  cout << ans << endl;
}