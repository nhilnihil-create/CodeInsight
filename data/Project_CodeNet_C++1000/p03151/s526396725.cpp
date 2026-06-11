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

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll minus = 0, ans = 0;
  rep(i, n) {
    ll b;
    cin >> b;
    a[i] -= b;
    if(a[i] < 0) {
      minus += a[i];
      ans++;
    }
  }
  sort(all(a), greater<ll>());
  rep(i, n) {
    if(minus >= 0) break;
    minus += a[i];
    ans++;
  }
  if(minus < 0) ans = -1;
  cout << ans << endl;
}