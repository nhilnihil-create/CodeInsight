#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
#define ll long long

signed main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> a(m);
  rep(i,m) {
    int x,y;
    cin >> x >> y;
    a[i]={x,y};
  }
  sort(a.begin(),a.end());
  
  int s = a[0].first;
  int e = a[0].second;
  int ans = 1;
  FOR(i,1,m) {
    if(e<=a[i].first) {
      ans++;
      s = a[i].first;
      e = a[i].second;
    }
    e = min(e, a[i].second);
  }
  cout << ans << endl;
  return 0;
}
