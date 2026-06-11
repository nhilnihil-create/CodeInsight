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
  double ans = 0;
  rep(i, 0, n) {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY")
      ans += x;
    else
      ans += x * 380000;
  }
  cout << ans << endl;
}
