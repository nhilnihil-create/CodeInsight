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

vl factor(ll n) {
  vl res;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      res.push_back(i);
      if(i * i != n) res.push_back(n / i);
    }
  }
  sort(all(res));
  return res;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vl f = factor(m);
  ll ans = 1;
  for(ll i : f)
    if(m / i >= n) ans = i;
  cout << ans << endl;
}