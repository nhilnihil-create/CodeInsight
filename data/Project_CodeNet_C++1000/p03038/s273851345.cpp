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
  cin >> n >> m;
  map<ll, ll, greater<ll>> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    mp[a]++;
  }
  rep(i, m) {
    ll b, c;
    cin >> b >> c;
    mp[c] += b;
  }
  ll ans = 0, cnt = n;
  for(auto v : mp) {
    ll k = v.first;
    ll num = v.second;
    if(cnt > num) {
      ans += k * num;
      cnt -= num;
      continue;
    }
    ans += k * cnt;
    break;
  }
  cout << ans << endl;
}