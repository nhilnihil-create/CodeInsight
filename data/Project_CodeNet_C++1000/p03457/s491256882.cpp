#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  int nt, nx, ny;
  nt = nx = ny = 0;
  rep(i, n){
    int t, x, y;
    cin >> t >> x >> y;
    int d = abs(x - nx) + abs(y - ny);
    int dt = t - nt;
    // cerr << d << " " << dt << endl;
    if((d > dt) || (dt % 2 != d % 2)){
      cout << "No" << endl;
      return 0;
    }
    nt = t; nx = x; ny = y;
  }
  cout << "Yes" << endl;
  return 0;
}