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

int x[MX];
int y[MX];
int z[MX];
vector<int> ma;
int ans;
signed main() {
  int n,m;
  cin >> n >> m;
  rep(i,n) cin >> x[i] >> y[i] >> z[i];
  ma.resize(n);
  rep(i,8) {
    int a = (i&1)?-1:1;
    int b = (i>>1&1)?-1:1;
    int c = (i>>2&1)?-1:1;
    // cout <<i<<" "<< (i&1)<<" "<<(i>>1&1)<<" "<<(i>>2&1) << endl;
    // cout << c << endl;
    rep(j,n) {
      ma[j] = a*x[j]+b*y[j]+c*z[j];
    }
    sort(ma.begin(), ma.end(), greater<int>());
    int cakes = 0;
    rep(j,m) cakes += ma[j];
    // cout << cakes << endl;
    ans = max(ans, cakes);
  }
  cout << ans << endl;

  return 0;
}
