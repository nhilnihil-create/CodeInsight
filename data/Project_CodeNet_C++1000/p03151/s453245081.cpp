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
  cin >> n;
  vl a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  ll ans = 0, m = 0;
  priority_queue<ll> q;
  rep(i, n) {
    if(a[i] > b[i])
      q.push(a[i] - b[i]);
    else if(a[i] < b[i]) {
      m += b[i] - a[i];
      ans++;
    }
  }
  while(!q.empty() && m > 0) {
    ll k = q.top();
    q.pop();
    m -= k;
    ans++;
  }
  if(m > 0) ans = -1;
  cout << ans << endl;
}