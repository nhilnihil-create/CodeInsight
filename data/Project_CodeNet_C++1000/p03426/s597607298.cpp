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
int a;
signed main() {
  int h,w,d;
  cin >> h >> w >> d;
  vector<int> dd(h*w+1,0);
  rep(i,h) {
    rep(j,w) {
      cin >> a;
      x[a]=i;
      y[a]=j;
    }
  }
  for(int i = d+1; i<=h*w; i++) {
    dd[i]= dd[i-d]+abs(x[i-d]-x[i])+abs(y[i-d]-y[i]);
  }
  int q;
  cin >> q;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    cout << dd[r]-dd[l] << endl;
  }

  return 0;
}
