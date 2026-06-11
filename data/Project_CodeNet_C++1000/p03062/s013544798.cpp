#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  rep(i, n) {
    cin >> a[i];
    if (a[i] < 0) cnt++;
  }

  ll ans = 0;
  rep(i, n) ans += abs(a[i]);
  if (cnt % 2 != 0) {
    int min_v = 1001001001;
    rep(i, n) min_v = min(min_v, abs(a[i]));
    ans -= 2 * min_v;
  }
  cout << ans << endl;

  return 0;
}
