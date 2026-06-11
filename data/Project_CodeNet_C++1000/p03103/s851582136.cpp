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
  ll n, m;
  cin >> n >> m;
  vector<P> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  sort(all(p));
  ll ans = 0;
  rep(i, n) {
    ll y = p[i].first;
    ll c = p[i].second;
    if(m <= c) {
      ans += y * m;
      break;
    } else {
      m -= c;
      ans += y * c;
    }
  }
  cout << ans << endl;
}