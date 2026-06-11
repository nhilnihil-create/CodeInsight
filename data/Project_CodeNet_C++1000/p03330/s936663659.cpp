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
  int n, c;
  cin >> n >> c;
  vector<vi> d(c, vi(c)), a(n, vi(n)), cost(c, vi(3, 0));
  rep(i, c) rep(j, c) cin >> d[i][j];
  rep(i, n) rep(j, n) {
    cin >> a[i][j];
    a[i][j]--;
  }
  rep(k, c) rep(i, n) rep(j, n) cost[k][(i + j) % 3] += d[a[i][j]][k];
  int ans = 1e9;
  rep(i, c) rep(j, c) rep(k, c) {
    if(i == j || j == k || k == i) continue;
    int now = cost[i][0] + cost[j][1] + cost[k][2];
    ans = min(ans, now);
  }
  cout << ans << endl;
}