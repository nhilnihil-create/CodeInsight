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
  vl a(3);
  rep(i, 3) cin >> a[i];
  sort(all(a));
  ll ans = a[2] - a[1];
  a[0] += ans;
  ans += (a[2] - a[0] + 1) / 2;
  ans += (a[2] - a[0]) % 2;
  cout << ans << endl;
}