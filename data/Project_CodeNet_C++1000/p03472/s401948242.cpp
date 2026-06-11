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
  ll n, h;
  cin >> n >> h;
  vector<P> p;
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    p.push_back({a, 0});
    p.push_back({b, 1});
  }
  sort(all(p), greater<P>());
  ll ans = 0, now = 0;
  for(ll i = 0; now < h; i++) {
    ll a = p[i].first;
    ll t = p[i].second;
    if(t == 1) {
      ans++;
      now += a;
    } else {
      ans += (h - now + a - 1) / a;
      break;
    }
  }
  cout << ans << endl;
}