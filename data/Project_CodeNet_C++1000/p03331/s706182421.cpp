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

  int n;
  cin >> n;
  int ans = 1e9;
  rep(i, 1, n) {
    int t = i;
    int j = n - i;
    int x = 0;
    while (t) {
      x += t % 10;
      t /= 10;
    }
    while (j) {
      x += j % 10;
      j /= 10;
    }
    chmin(ans, x);
  }
  cout << ans << endl;
}
