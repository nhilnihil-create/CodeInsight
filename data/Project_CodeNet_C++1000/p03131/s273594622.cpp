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
  ll k, a, b;
  cin >> k >> a >> b;
  ll n = 1;
  if(b - a > 1) {
    k -= a - 1;
    if(k <= 0)
      n += k;
    else {
      n = a;
      n += k / 2 * (b - a);
      n += k % 2;
    }
  } else
    n += k;
  cout << n << endl;
}