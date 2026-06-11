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
  ll h, w, d;
  cin >> h >> w >> d;
  ll n = h * w;
  vector<P> p(n + 1);
  rep(i, h) rep(j, w) {
    ll a;
    cin >> a;
    p[a] = P(i, j);
  }
  ll q;
  cin >> q;
  vl l(q), r(q);
  rep(i, q) cin >> l[i] >> r[i];
  vl cost(n + 1, 0);
  rep2(i, 1, d + 1) {
    ll j = i;
    while(j + d <= n) {
      ll xf = p[j].first;
      ll yf = p[j].second;
      ll xt = p[j + d].first;
      ll yt = p[j + d].second;
      cost[j + d] = cost[j] + abs(xt - xf) + abs(yt - yf);
      j += d;
    }
  }
  rep(i, q) cout << cost[r[i]] - cost[l[i]] << '\n';
}