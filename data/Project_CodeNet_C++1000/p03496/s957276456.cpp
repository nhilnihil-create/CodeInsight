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
  int n;
  cin >> n;
  vector<int> a(n);
  int ma = -1e9, mi = 1e9;
  int mai,mii;
  rep(i,n){
    cin >> a[i];
    ma = max(ma,a[i]);
    mi = min(mi,a[i]);
    if(ma==a[i]) mai=i;
    if(mi==a[i]) mii=i;
  }
  ++mai; ++mii;

  vector<P> ans;
  if(abs(ma)>=abs(mi)){
    rep(i,n) if(a[i]<0) ans.emplace_back(mai,i+1);
    rep(i,n-1) ans.emplace_back(i+1,i+2);
  }else{
    rep(i,n) if(a[i]>0) ans.emplace_back(mii,i+1);
    rep(i,n-1) ans.emplace_back(n-i,n-i-1);
  }
  int m = ans.size();
  cout << m << endl;
  rep(i,m) cout << ans[i].first << " " << ans[i].second << endl;
}