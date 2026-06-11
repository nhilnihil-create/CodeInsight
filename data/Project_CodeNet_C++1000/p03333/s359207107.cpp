#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  int n; cin >> n;
  vector<int> l(n + 1), r(n + 1);
  for(int i = 1; i <= n; ++i)
    cin >> l[i] >> r[i];
  ll res = 0;
  sort(l.rbegin(), l.rend());
  sort(r.begin(), r.end());
  for(int i = 0; i <= n; ++i){
    if(l[i] < r[i]) continue;
    res += l[i] - r[i];
  }
  cout << res * 2;
}
