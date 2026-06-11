#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int d,g;
  cin >> d >> g;
  g /= 100;
  vector<int> p(d), c(d);
  rep(i,d) cin >> p[i] >> c[i];
  rep(i,d) c[i] /= 100;

  int ans = 1e9;
  rep(b,1<<d){
    int res = 0, r = g;
    vector<int> n(11);
    rep(i,d){
      if(b>>i&1){
        r -= (i+1)*p[i] + c[i];
        res += p[i];
      }else{
        n[i+1] += p[i]-1;
      }
    }
    for(int i = 10; i>0; --i){
      if(r<=0) break;
      int cnt = min(n[i],(r+i-1)/i);
      r -= cnt*i;
      res += cnt;
    }
    if(r<=0) ans = min(ans,res);
  }
  cout << ans << endl;
}
