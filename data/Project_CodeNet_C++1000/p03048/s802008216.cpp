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

  int R, G, B, n;
  cin >> R >> G >> B >> n;
  int ans = 0;
  rep(r, 0, 3001) {
    rep(g, 0, 3001) {
      int t = r * R + g * G;
      if (t > n)
        break;
      if ((n - t) % B)
        continue;
      ans++;
    }
  }

  cout << ans << endl;
}
