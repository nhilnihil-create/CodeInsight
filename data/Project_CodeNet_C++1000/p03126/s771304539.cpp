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
  ll n, m;
  cin >> n >> m;
  vl c(m + 1, 0);
  rep(i, n) {
    ll k;
    cin >> k;
    rep(j, k) {
      ll a;
      cin >> a;
      c[a]++;
    }
  }
  ll ans = 0;
  rep(i, m + 1) if(c[i] == n) ans++;
  cout << ans << endl;
}