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
  ll t;
  cin >> t;
  rep(_, t) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a < b || d < b || a % b > c) {
      // cout << 1 << ' ';
      cout << "No" << endl;
      continue;
    }
    if(c >= b - 1) {
      // cout << 2 << ' ';
      cout << "Yes" << endl;
      continue;
    }
    ll g = gcd(b, d);
    ll y = a % b;
    ll k = (c - y) / g + 1;
    if(g * k + y < b) {
      // cout << 3 << ' ';
      cout << "No" << endl;
    } else {
      // cout << 4 << ' ';
      cout << "Yes" << endl;
    }
  }
}