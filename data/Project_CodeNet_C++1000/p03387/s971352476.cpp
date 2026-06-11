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
  int a,b,c;
  cin >> a >> b >> c;
  int mi = min({a,b,c}),ma = max({a,b,c});
  int v[] = {a,b,c};
  int ans = 1e9;
  for(int x = mi;x<=ma;++x){
    int res = 0;
    rep(i,3){
      if(v[i]>x){
        res += v[i]-x;
      }else{
        res += (x-v[i]+1)/2;
        if((x-v[i])%2) ++res;
      }
    }
    ans = min(ans,res);
  }
  cout << ans << endl;
}
