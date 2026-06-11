#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const ll INF=1e9;

int main(){
  int h,w;
  cin>>h>>w;
  
  ll d[10][10];
  ll x;
  rep(i,10){
    rep(j,10){
      cin>>x;
      d[i][j]=x;
    }
  }
  
  for(int k=0;k<10;k++){
    for(int i=0;i<10;i++){
      for(int j=0;j<10;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
  }
  
  vector<ll> A(10,0);
  ll y;
  rep(i,h){
    rep(i,w){
      cin>>y;
      if(y!=-1) A[y]++;
    }
  }
  
  ll ans=0;
  rep(i,10) ans+=A[i]*d[i][1];
  
  cout<<ans<<endl;
  
  return 0;
}