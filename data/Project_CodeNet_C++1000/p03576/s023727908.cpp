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
  ll n, K;
  cin >> n >> K;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));
  ll ans = 4e18;
  rep(i, n - K + 1) rep(j, n) rep(k, n) {
    ll x1 = p[i].first;
    ll y1 = p[j].second;
    ll y2 = p[k].second;
    if(y2 < y1) continue;
    ll cnt = 0, x2 = x1;
    rep(a, n) {
      ll x = p[a].first;
      ll y = p[a].second;
      if(x1 <= x && y1 <= y && y <= y2) cnt++;
      if(cnt == K) {
        x2 = x;
        break;
      }
    }
    if(cnt < K) continue;
    ll now = (x2 - x1) * (y2 - y1);
    ans = min(ans, now);
  }
  cout << ans << endl;
}