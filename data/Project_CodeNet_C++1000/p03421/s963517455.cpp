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
  ll n, a, b;
  cin >> n >> a >> b;
  ll k = a * b;
  if(k < n || a + b - 1 > n) {
    cout << -1 << endl;
    return 0;
  }
  vl v;
  k -= n;
  rep(i, a) {
    ll bb = b;
    if(k >= bb - 1) {
      k -= bb - 1;
      bb = 1;
    } else {
      bb -= k;
      k = 0;
    }
    rep(j, bb) v.push_back((i + 1) * b - j);
  }
  vl sv = v;
  sort(all(sv));
  for(auto u : v) {
    ll in = lower_bound(all(sv), u) - sv.begin() + 1;
    cout << in << ' ';
  }
  cout << endl;
}