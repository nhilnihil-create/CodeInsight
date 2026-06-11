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
  ll h, w;
  cin >> h >> w;
  vector<vl> g(h + 2, vl(w + 2, -2));
  queue<pair<int, int>> q;
  rep2(i, 1, h + 1) rep2(j, 1, w + 1) {
    char c;
    cin >> c;
    if(c == '#') {
      g[i][j] = 0;
      q.push({i, j});
    } else
      g[i][j] = -1;
  }
  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    rep(k, 4) {
      int ni = i + dir[k];
      int nj = j + dir[k + 1];
      if(g[ni][nj] != -1) continue;
      g[ni][nj] = g[i][j] + 1;
      q.push({ni, nj});
    }
  }
  ll ans = 0;
  rep2(i, 1, h + 1) rep2(j, 1, w + 1) ans = max(ans, g[i][j]);
  cout << ans << endl;
}