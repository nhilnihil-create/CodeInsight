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
const int inf = 1e13;
const int mod = 1e9+7;
#define ll long long

signed main() {
   int n,m;
   cin >> n>>m;
   vector<int> l(m);
   vector<int> r(m);
   int lll = 0;
   int rrr = n; 
   rep(i,m) {
       cin >> l[i] >>r[i];
       lll = max(l[i],lll);
       rrr = min(r[i],rrr);
   }
   //cout << rrr  << endl;
   int tmp = 0;
   int ans =max(tmp, rrr-lll+1); 
   cout << ans << endl;

  return 0;
}
