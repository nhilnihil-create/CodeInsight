#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll>x(n),y(n),z(n);
  vector<vector<ll>>ans(8,vector<ll>(n));
  for(int i=0; i<n; i++) cin >> x[i] >> y[i] >> z[i];
  
  for(int i=0; i<8; i++){
    for(int j=0; j<n; j++){
      if(i>>0 & 1)ans[i][j]+=x[j];
      else ans[i][j]-=x[j];
      if(i>>1 & 1)ans[i][j]+=y[j];
      else ans[i][j]-=y[j];
      if(i>>2 & 1)ans[i][j]+=z[j];
      else ans[i][j]-=z[j];
    }
  }
  
  ll MAX=0;
  for(int i=0; i<8; i++){
    ll max_kari=0;
    sort(ans[i].begin(),ans[i].end());
    reverse(ans[i].begin(),ans[i].end());
    for(int j=0; j<m; j++){
      max_kari+=ans[i][j];
    }
    MAX=max(MAX,max_kari);
  }
  
  cout << MAX << endl;
}
  
  
  
