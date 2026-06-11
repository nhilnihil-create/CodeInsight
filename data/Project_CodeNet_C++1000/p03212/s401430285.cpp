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
  cin >> n;
  ll ans = 0;
  vl v = {3, 5, 7};
  rep2(k, 3, 11) {
    ll m = pow(3, k);
    rep(i, m) {
      vl a(k);
      ll x = i;
      set<ll> st;
      rep(j, k) {
        a[j] = x % 3;
        x /= 3;
        st.insert(a[j]);
      }
      ll s = 0;
      rep(j, k) s += v[a[j]] * pow(10, j);
      if(s <= n && st.size() == 3) ans++;
    }
  }
  cout << ans << endl;
}