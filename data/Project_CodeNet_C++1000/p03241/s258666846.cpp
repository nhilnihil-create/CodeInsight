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
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for(int i = 1; i * i <= m; i++){
    if(m % i != 0) continue;
    if((ll)n*i <= (ll)m){
      ans = max(ans, i);
    }
    int j = m / i;
    if((ll)n*j <= (ll)m){
      ans = max(ans, j);
    }
  }
  cout << ans << endl;
  return 0;
}