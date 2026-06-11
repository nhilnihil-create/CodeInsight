#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;
  // Ai < Bj < Ck になる組 (i,j,k) の個数を求める場合
  // i を固定すれば求める個数は Ai < Bj なる i の個数と
  // Bj < Ck なる k の個数の積
  rep(i, 0, n) {
    ll mid = b[i];
    ll aa = lower_bound(a.begin(), a.end(), mid) - a.begin();
    ll cc = c.end() - upper_bound(c.begin(), c.end(), mid);
    ans += aa * cc;
  }
  cout << ans << endl;
  return 0;
}
