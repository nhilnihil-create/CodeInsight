#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  ll h, w; cin >> h >> w;
  int ans = 0;
  while (n--) {
    ll x, y; cin >> x >> y;
    if ((x >= h && y >= w)) ans++;
  }
  cout << ans << endl;

  return 0;
}
