#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<p> cb;
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    cb.emplace_back(c, b);
  }
  sort(a.begin(), a.end());
  sort(cb.begin(), cb.end());
  int min = a[0];
  int id = 0;
  rep(i, m) {
    if (min >= cb[m - 1 - i].first) break;
    // cout << min << endl;
    // cout << cb[m - 1 - i].first << endl;
    rep(j, cb[m - 1 - i].second) {
      if (a[id] >= cb[m - 1 - i].first) break;
      a[id] = cb[m - 1 - i].first;
      id++;
    }
    // rep(i, n) cout << a[i] << ' ';
    // cout << endl;
    min = a[id];
  }
  ll ans = 0;
  rep(i, n) ans += a[i];
  cout << ans << endl;
  return 0;
}