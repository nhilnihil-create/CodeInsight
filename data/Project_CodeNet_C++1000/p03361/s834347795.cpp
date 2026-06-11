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
  int h, w;
  cin >> h >> w;
  vector<vi> g(h + 2, vi(w + 2, 0));
  rep2(i, 1, h + 1) rep2(j, 1, w + 1) {
    char c;
    cin >> c;
    if(c == '#') g[i][j] = 1;
  }
  bool ans = true;
  rep2(i, 1, h + 1) rep2(j, 1, w + 1) {
    if(g[i][j] == 0) continue;
    bool ok = false;
    rep(k, 4) {
      ll ni = i + dir[k];
      ll nj = j + dir[k + 1];
      if(g[ni][nj] == 1) ok = true;
    }
    if(!ok) ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
}