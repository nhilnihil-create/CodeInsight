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

  double N;
  cin >> N;

  rep(h, 1, 3501) {
    rep(n, 1, 3501) {
      double w = (N * h * n) / (4 * h * n - N * n - N * h);
      if (w > 0 && w == (int)w) {
        cout << h << " " << n << " " << (int)w << endl;
        return 0;
      }
    }
  }
}
