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
  if(fopen("A.INP", "r")){
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  }
  int h, w; cin >> h >> w;
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for(auto & x : a){
    cin >> x.fi >> x.se;
  }
  sort(a.begin(), a.end());
  int res = h, o = 0;
  for(auto & x : a){
    if(x.fi == x.se + o) ++o;
    else if(x.fi >= x.se + o + 1)
      res = min(res, x.fi - 1);
  }
  cout << res;
}
