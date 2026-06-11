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
  ll n, a, b;
  cin >> n >> a >> b;
  if(a * b < n || a + b - 1 > n) {
    cout << -1 << '\n';
    return 0;
  }
  ll r = a * b - n;
  vl ans;
  rep(i, a) {
    ll nb;
    if(r < b - 1) {
      nb = b - r;
      r = 0;
    } else {
      nb = 1;
      r -= b - 1;
    }
    rep(j, nb) ans.push_back((i + 1) * b - j);
  }
  vl sa = ans;
  sort(all(sa));
  rep(i, n) {
    ll in = lower_bound(all(sa), ans[i]) - sa.begin();
    cout << in + 1 << (i == n - 1 ? '\n' : ' ');
  }
}