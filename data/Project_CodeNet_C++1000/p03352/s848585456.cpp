#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int x; cin >> x;
  int n = x;
  int p = 10;
  vector<vector<int>> fac(n+1,vector<int>(p+1));
  rep(i,n+1)
    rep(j,p+1) fac[i][j] = 1;
    
  for(int i = 1;i<=x;i++){
    for(int j = 1;j<=p;j++){
      fac[i][j] = fac[i][j-1]*i;
    }
  }

  int ans = -1;
  for(int i = 1;i<=x;i++){
    for(int j = 2;j<=p;j++){
      if(fac[i][j]<=x) ans = max(ans,fac[i][j]);
    }
  }

  cout << ans << endl;
  
  return 0;
}
