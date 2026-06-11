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
  ll n;
  cin >> n;
  vl a(n), b(n);
  bool ok = false;
  rep(i, n) {
    cin >> a[i] >> b[i];
    if(a[i] != b[i]) ok = true;
  }
  if(!ok) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = accumulate(all(a), 0LL);
  ll mn = 1e18;
  rep(i, n) {
    if(a[i] > b[i]) mn = min(mn, b[i]);
  }
  ans -= mn;
  cout << ans << endl;
}