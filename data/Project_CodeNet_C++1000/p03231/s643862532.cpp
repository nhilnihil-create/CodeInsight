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
  string s, t;
  cin >> n >> m >> s >> t;
  ll l = n / gcd(n, m) * m;
  map<ll, char> mp;
  rep(i, n) mp[i * l / n + 1] = s[i];
  bool ok = true;
  rep(i, m) {
    ll j = i * l / m + 1;
    if(mp.count(j) && mp[j] != t[i]) ok = false;
  }
  cout << (ok ? l : -1) << endl;
}