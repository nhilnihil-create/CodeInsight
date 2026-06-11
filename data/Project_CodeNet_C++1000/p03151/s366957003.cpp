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
  vl a(n);
  rep(i, n) cin >> a[i];
  priority_queue<ll> q;
  ll s1 = 0, s2 = 0;
  ll ans = 0;
  rep(i, n) {
    ll b;
    cin >> b;
    a[i] -= b;
    if(a[i] > 0) {
      q.push(a[i]);
      s2 += a[i];
    } else if(a[i] < 0) {
      s1 -= a[i];
      ans++;
    }
  }
  if(s1 > s2) {
    cout << -1 << endl;
    return 0;
  }
  while(s1 > 0) {
    ll now = q.top();
    q.pop();
    s1 -= now;
    ans++;
  }
  cout << ans << endl;
}