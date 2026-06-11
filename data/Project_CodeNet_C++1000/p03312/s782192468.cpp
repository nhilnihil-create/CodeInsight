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
  vl cum(n + 1, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    cum[i + 1] = cum[i] + a;
  }
  ll ans = 1e18;
  rep2(k, 2, n - 1) {
    vl v(4);
    ll in =
        lower_bound(cum.begin(), cum.begin() + k + 1, cum[k] / 2) - cum.begin();
    ll p1 = cum[in], p2 = cum[in - 1], q1 = cum[k] - cum[in],
       q2 = cum[k] - cum[in - 1];
    if(abs(p1 - q1) > abs(p2 - q2)) {
      v[0] = p2;
      v[1] = q2;
    } else {
      v[0] = p1;
      v[1] = q1;
    }
    in = lower_bound(cum.begin() + k + 1, cum.end(), (cum[n] + cum[k]) / 2) -
         cum.begin();
    p1 = cum[in] - cum[k], p2 = cum[in - 1] - cum[k];
    q1 = cum[n] - cum[in], q2 = cum[n] - cum[in - 1];
    if(abs(p1 - q1) > abs(p2 - q2)) {
      v[2] = p2;
      v[3] = q2;
    } else {
      v[2] = p1;
      v[3] = q1;
    }
    // rep(i, 4) cout << v[i] << ' ';
    // cout << endl;
    sort(all(v));
    ans = min(ans, v[3] - v[0]);
  }
  cout << ans << endl;
}