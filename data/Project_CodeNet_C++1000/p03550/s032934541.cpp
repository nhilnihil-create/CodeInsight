#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, z, w;
  cin >> n >> z >> w;
  vl a(n);
  rep(i, n) cin >> a[i];
  ll ans;
  if(n == 1)
    ans = abs(a[0] - w);
  else {
    ans = max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1]));
  }
  cout << ans << endl;
}