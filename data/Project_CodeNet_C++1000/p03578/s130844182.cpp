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
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    ll d;
    cin >> d;
    mp[d]++;
  }
  cin >> m;
  bool ok = true;
  rep(i, m) {
    ll t;
    cin >> t;
    if(mp[t] <= 0) ok = false;
    mp[t]--;
  }
  cout << (ok ? "YES" : "NO") << endl;
}