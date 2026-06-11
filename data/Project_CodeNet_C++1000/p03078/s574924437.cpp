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

  int x, y, z, k;
  cin >> x >> y >> z >> k;

  vector<ll> a(x), b(y), c(z);
  rep(i, 0, x) cin >> a[i];
  rep(i, 0, y) cin >> b[i];
  rep(i, 0, z) cin >> c[i];

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());

  vector<ll> ans;

  rep(i, 0, x) {
    rep(j, 0, y) {
      rep(m, 0, z) {
        if ((i + 1) * (j + 1) * (m + 1) <= k)
          ans.push_back(a[i] + b[j] + c[m]);
        else
          break;
      }
    }
  }

  sort(ans.rbegin(), ans.rend());

  rep(i, 0, k) cout << ans[i] << endl;
}
