#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll k;
  cin >> k;
  vl a(k);
  rep(i, k) cin >> a[i];
  reverse(all(a));
  ll nl = 2, nr = 2, l, r;
  rep(i, k) {
    l = nl;
    r = nr;
    nl = (l + a[i] - 1) / a[i] * a[i];
    nr = (r / a[i] + 1) * a[i] - 1;
    if(nl > r || nr < l) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << nl << ' ' << nr << endl;
}