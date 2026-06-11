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
  vl a(n), b(n);
  ll s;
  rep(i, n) {
    cin >> a[i];
    s -= a[i];
  }
  rep(i, n) {
    cin >> b[i];
    s += b[i];
  }
  bool ok = true;
  if(s < 0) ok = false;
  ll p = 0, m = 0;
  rep(i, n) {
    if(a[i] > b[i])
      m += a[i] - b[i];
    else
      p += (b[i] - a[i] + 1) / 2;
  }
  if(max(p, m) > s) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
}