#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  int n; cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i){
    cin >> p[i]; --p[i];
    q[p[i]] = i;
  }
  int now = 1, res = 0;
  for (int i = 1; i < n; ++i){
    res = max(res, now);
    if (q[i] > q[i - 1]) ++now;
    else now = 1;
  }
  res = max(res, now);
  cout << n - res;
}
