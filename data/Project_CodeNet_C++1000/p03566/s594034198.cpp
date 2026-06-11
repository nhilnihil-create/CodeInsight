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
using ld = long double;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ld> t(n),v(n);
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> v[i];

  vector<ld> m(n);
  rep(i,n-1){
    int j = n-1-i;
    m[j-1] = min(m[j]+t[j],v[j]);
  }

  ld ans = 0;
  ld vl = 0;
  rep(i,n){
    ld vr = min({vl+t[i],v[i],m[i]});
    ld tl = max(ld(0),v[i]-vl);
    ld tr = max(ld(0),v[i]-vr);
    if(tl+tr>t[i]){
      ld d = (t[i]-tl-tr)/2;
      tl -= d;
      tr -= d;
      if(tl<0) tr += tl, tl = 0;
      if(tr<0) tl += tr, tr = 0;
    }
    ans += (vl+vl+tl)*tl/2 
        + (vr+vr+tr)*tr/2 
        + (t[i]-tl-tr)*v[i];
    vl = vr;
  }
  printf("%.10Lf\n",ans);
}