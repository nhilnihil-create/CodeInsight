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
  ll n, y;
  cin >> n >> y;
  rep(i, n + 1) rep(j, n + 1) {
    ll k = n - i - j;
    if(k < 0) continue;
    if(10000 * i + 5000 * j + 1000 * k != y) continue;
    cout << i << ' ' << j << ' ' << k << endl;
    return 0;
  }
  cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}