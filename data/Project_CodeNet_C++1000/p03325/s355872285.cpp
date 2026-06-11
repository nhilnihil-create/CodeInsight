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
  ll ans = 0;
  rep(i, n){
    int a;
    cin >> a;
    int co = 0;
    if(a == 0 || a % 2 != 0) continue;
    while(1){
      if(a == 0 || a % 2 != 0) break;
      co++;
      a /= 2;
    }
    ans += co;
  }
  cout << ans << endl;
  return 0;
}