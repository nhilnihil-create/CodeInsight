#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  ll N,C;
  cin >> N >> C;
  vector<vector<ll>> D(C,vector<ll>(C,0));
  vector<vector<ll>> c(N,vector<ll>(N));
  for(ll i=0;i<C;++i){
    for(ll j=0;j<C;++j){
      cin >> D[i][j];      
    }
  }
  for(ll i=0;i<N;++i){
    for(ll j=0;j<N;++j){
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  ll grid[3][C];
  for(ll i=0;i<3;++i){
    for(ll j=0;j<C;++j){
      grid[i][j]=0;
    }
  }
  //modごとの個数数える
  for(ll i=0;i<N;++i){
    for(ll j=0;j<N;++j){
      if((i+j+2)%3==0) grid[0][c[i][j]]++;
      else if((i+j+2)%3==1) grid[1][c[i][j]]++;
      else if((i+j+2)%3==2) grid[2][c[i][j]]++;
    }
  }
  //色塗り全通り mod0,1,2をi,j,k
  ll ans=1e9;
  ll tmp=0;
  for(ll i=0;i<C;++i){
    for(ll j=0;j<C;++j){
      for(ll k=0;k<C;++k){
        if(i==j || j==k || i==k) continue;
        tmp =0;
        //mod0
        for(ll t=0;t<C;++t){
          tmp += grid[0][t]*D[t][i];
        }
        //mod1
        for(ll t=0;t<C;++t){
          tmp += grid[1][t]*D[t][j];
        }
        //mod2
        for(ll t=0;t<C;++t){
          tmp += grid[2][t]*D[t][k];
        }
        ans = min(ans,tmp);
      }
    }
  }
  cout << ans << endl;
}