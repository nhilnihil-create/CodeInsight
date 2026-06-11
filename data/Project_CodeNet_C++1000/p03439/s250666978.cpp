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
  ll n;
  string s;
  cin >> n;
  cout << 0 << endl;
  cin >> s;
  if(s == "Vacant") return 0;
  ll l = 0, r = n / 2 + 1;
  while(l + 1 < r) {
    ll x = (l + r) / 2 * 2;
    string t;
    cout << x << endl;
    cin >> t;
    if(t == "Vacant") return 0;
    if(t == s)
      l = x / 2;
    else
      r = x / 2;
  }
  string t;
  cout << l * 2 + 1 << endl;
  cin >> t;
  return 0;
}