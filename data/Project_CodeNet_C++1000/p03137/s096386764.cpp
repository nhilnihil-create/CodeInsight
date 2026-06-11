#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,M;
  cin>>N>>M;
  vector<ll> x(M);
  for(ll i=0;i<M;i++){
    cin>>x.at(i);
  }
  if(N>=M){cout<<0<<endl;}
  else{
    sort(x.begin(),x.end());
    vector<ll> sa(M-1);
    for(ll i=0;i<M-1;i++){
      sa.at(i)=x.at(i+1)-x.at(i);
    }
    sort(sa.begin(),sa.end());
    ll ans=0;
    for(ll i=0;i<M-N;i++){
      ans+=sa.at(i); 
    }
    cout<<ans<<endl;
  }
}