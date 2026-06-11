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
  int h, w;
  cin >> h >> w;
  vector<vi> g(h, vi(w));
  rep(i, h) rep(j, w) cin >> g[i][j];
  vector<tuple<ll, ll, ll, ll>> ans;
  rep(i, h) {
    rep(j, w - 1) {
      if(g[i][j] % 2 == 0) continue;
      ans.push_back(make_tuple(i + 1, j + 1, i + 1, j + 2));
      g[i][j + 1]++;
    }
    if(g[i][w - 1] % 2 == 0 || i == h - 1) continue;
    ans.push_back(make_tuple(i + 1, w, i + 2, w));
    g[i + 1][w - 1]++;
  }
  cout << ans.size() << '\n';
  for(auto v : ans) {
    ll i, j, ni, nj;
    tie(i, j, ni, nj) = v;
    printf("%d %d %d %d\n", i, j, ni, nj);
  }
}