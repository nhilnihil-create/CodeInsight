#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,a,b) for(ll i=a;i<b;i++)
int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n),b(n);
  rep(i,0,n){
    cin>>a[i]>>b[i];
  }
  vector<ll> ks(1);
  ks[0]=k;
  bool f=0;
  rep(i,0,30){
    if(k&(1<<i)){
      if(f){
      	ks.push_back(k^(1<<i)|((1<<i)-1));
      }
    }
    else f=1;
  }
  ll ans=0;
  rep(j,0,ks.size()){
      ll cnt = 0;
    rep(i,0,n){
      if((a[i]|ks[j])==ks[j]) {
        cnt+=b[i];
      }
    }
    if(ans<cnt)ans=cnt;
  }
  cout<<ans;
}