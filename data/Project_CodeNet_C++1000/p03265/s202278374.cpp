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
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll dx = x2 - x1;
  ll dy = y2 - y1;
  printf("%d %d %d %d\n", x2 - dy, y2 + dx, x1 - dy, y1 + dx);
}