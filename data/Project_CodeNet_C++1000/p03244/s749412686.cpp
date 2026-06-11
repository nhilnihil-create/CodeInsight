#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

bool cmp(ii &a, ii &b) {
  return a.sc > b.sc;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int, int> mo, me;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    if (i % 2) mo[t]++;
    else me[t]++;
  }
  vector<ii> vo(all(mo)), ve(all(me));
  sort(all(vo), cmp);
  sort(all(ve), cmp);
  if (vo[0].fi != ve[0].fi) {
    cout << n - (vo[0].sc + ve[0].sc) << '\n';
    return 0;
  }
  if (vo.size() == 1 && ve.size() == 1) {
    cout << n / 2 << '\n';
    return 0;
  }
  int ans = 2e9;
  if (vo.size() >= 2) ans = min(ans, n - (vo[1].sc + ve[0].sc));
  if (ve.size() >= 2) ans = min(ans, n - (vo[0].sc + ve[1].sc));
  cout << ans << '\n';
}
