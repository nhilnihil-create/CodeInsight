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
  ll n, m, Q;
  cin >> n >> m >> Q;
  vector<vl> g(n, vl(n, 0));
  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    l--;
    r--;
    g[l][r]++;
  }
  vector<vl> s(n + 1, vl(n + 1, 0));
  rep(i, n) rep(j, n) s[i + 1][j + 1] =
      s[i + 1][j] + s[i][j + 1] - s[i][j] + g[i][j];
  rep(_, Q) {
    ll p, q;
    cin >> p >> q;
    p--;
    cout << s[q][q] - s[p][q] - s[q][p] + s[p][p] << '\n';
  }
}