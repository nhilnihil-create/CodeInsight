#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(n);i++)
const ll INF = 1LL<<60;


int main(){
  ll H,W;
  cin>>H>>W;
  
  ll a[H][W];
  rep(i,H){
   rep(j,W){cin>>a[i][j];}
  }
 ll ans=0;
  
  vector<ll> Y1;
  vector<ll> X1;
  vector<ll> Y2;
  vector<ll> X2;
  
  rep(i,H){
    rep(j,W-1){
      if(a[i][j]%2==1){
          Y1.push_back(i+1);
          X1.push_back(j+1);
          Y2.push_back(i+1);
          X2.push_back(j+2);
          ans++;
          a[i][j+1]++;
      }
    }
  }
  
  rep(i,H-1){
    if(a[i][W-1]%2==1){
          Y1.push_back(i+1);
          X1.push_back(W);
          Y2.push_back(i+2);
          X2.push_back(W);
      ans++;
      a[i+1][W-1]++;
    }
  }
  
  cout<<ans<<endl;
  rep(i,ans){
   cout<<Y1[i]<<" "<<X1[i]<<" "<<Y2[i]<<" "<<X2[i]<<endl;
  }


}
