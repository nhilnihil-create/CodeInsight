#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i, n) { cin >> a[i]; }

  bool ng = (a[0] != 0);
  FOR(i, 1, n) {
    if (a[i] - a[i - 1] >= 2)
      ng = true;
  }

  if (ng) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  FOR(i, 1, n) {
    if (a[i - 1] < a[i]) {
      ans++;
    } else {
      ans += a[i];
    }
  }
  cout << ans << endl;
}
