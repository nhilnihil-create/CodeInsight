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
  vector<vl> g(h, vl(w));
  rep(i, h) rep(j, w) cin >> g[i][j];
  vl y, x, yd, xd;
  rep(i, h) rep(j, w) {
    if(g[i][j] % 2 == 0) continue;
    if(i == h - 1 && j == w - 1) continue;
    ll c = i, d = j;
    if(j == w - 1)
      c++;
    else
      d++;
    g[c][d]++;
    y.push_back(i + 1);
    x.push_back(j + 1);
    yd.push_back(c + 1);
    xd.push_back(d + 1);
  }
  cout << y.size() << '\n';
  rep(i, y.size()) cout << y[i] << ' ' << x[i] << ' ' << yd[i] << ' ' << xd[i]
                        << '\n';
}