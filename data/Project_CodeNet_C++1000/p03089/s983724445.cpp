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

  vector<int> v(n), ans;
  rep(i, 0, n) cin >> v[i];

  while (v.size()) {
    bool del = false;
    repr(i, 0, v.size()) {
      if (v[i] == i + 1) {
        ans.push_back(v[i]);
        v.erase(v.begin() + i);
        del = true;
        break;
      }
    }
    if (!del) {
      cout << -1 << endl;
      return 0;
    }
  }

  repr(i, 0, n) cout << ans[i] << endl;
}
