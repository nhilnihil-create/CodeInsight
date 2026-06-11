#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
  ll n,a,b,c[10000];
  ll x=0,y=0,z=0;
  cin>>n>>a>>b;
  for(ll i=0;i<n;i++){
	cin>>c[i];
  }
  for(ll i=0;i<n;i++){
	if(a>=c[i]){
      x++;
    }else if(a<c[i] && b>=c[i]){
      y++;
    }else if(b<c[i]){
      z++;
    }
  }
  cout<<min(x,min(y,z))<<"\n";
  return(0);
}