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
  vector<vl> c(3, vl(3));
  rep(i, 3) rep(j, 3) cin >> c[i][j];
  vl a(3, 0), b(3, 0);
  rep(j, 3) {
    b[j] = c[0][j];
    c[1][j] -= b[j];
    c[2][j] -= b[j];
  }
  bool ok = true;
  rep2(i, 1, 3) rep(j, 2) if(c[i][j] != c[i][j + 1]) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
}