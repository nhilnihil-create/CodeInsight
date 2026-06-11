#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

// ====================================================================

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  ll sowa = accumulate(a.begin(), a.end(), 0ll);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      ans = max(ans, sowa - b[i]);
    }
  }
  cout << ans << endl;
}
