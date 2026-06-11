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
  ll r, g, b, n;
  cin >> r >> g >> b >> n;
  ll ans = 0;
  rep(i, 3001) rep(j, 3001) {
    ll now = n - r * i - g * j;
    if(now >= 0 && now % b == 0) ans++;
  }
  cout << ans << endl;
}