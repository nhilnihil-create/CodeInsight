#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll x,y;
  cin>>x>>y;
  int ans=0;
  if(x%y==0){
    ans=-1;
  }
  ll n=1000000000000000000;
  for(ll i=x;i<n;i+=x){
    if(i%y==0){
      ;
    }
    else{
      ans=i;
      break;
    }
    if(ans){
      break;
    }
  }
  if(ans){
    cout<<ans<<endl;
  }
  else{
    cout<<-1<<endl;
  }
}