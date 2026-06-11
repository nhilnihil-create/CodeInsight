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
  vl a(3);
  cin >> n;
  rep(i, 3) cin >> a[i];
  vl l(n);
  rep(i, n) cin >> l[i];
  ll ans = 1e18;
  rep(i, pow(4, n)) {
    vl sum(4, 0), num(4, 0);
    ll k = i;
    rep(j, n) {
      sum[k % 4] += l[j];
      num[k % 4]++;
      k /= 4;
    }
    ll now = 0;
    bool ok = true;
    rep(j, 3) {
      if(num[j] == 0) ok = false;
      now += abs(sum[j] - a[j]);
      now += (num[j] - 1) * 10;
    }
    if(ok) ans = min(ans, now);
  }
  cout << ans << endl;
}