#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, C;
  cin >> n >> C;
  int d[C][C];
  vector<map<int, int>> vm(3);
  rep(i, 0, C) rep(j, 0, C) cin >> d[i][j];
  rep(i, 1, n + 1) rep(j, 1, n + 1) {
    int c;
    cin >> c;
    c--;
    vm[(i + j) % 3][c]++;
  }

  map<int, int> zero = vm[0], one = vm[1], two = vm[2];
  ll ans = 1e18;
  rep(i, 0, C) {
    ll sumzero = 0;
    for (auto m : zero)
      sumzero += d[m.first][i] * m.second;
    rep(j, 0, C) {
      ll sumone = 0;
      if (i == j)
        continue;
      for (auto m : one)
        sumone += d[m.first][j] * m.second;
      rep(k, 0, C) {
        ll sumtwo = 0;
        if (i == k || j == k)
          continue;
        for (auto m : two)
          sumtwo += d[m.first][k] * m.second;
        chmin(ans, sumzero + sumone + sumtwo);
      }
    }
  }
  cout << ans << endl;
}
