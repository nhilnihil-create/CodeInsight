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
  ll a, b, c, x;
  cin >> a >> b >> c >> x;
  ll ans = 0;
  rep(i, a + 1) rep(j, b + 1) rep(k, c + 1) {
    ll now = i * 500 + j * 100 + k * 50;
    if(now == x) ans++;
  }
  cout << ans << endl;
}