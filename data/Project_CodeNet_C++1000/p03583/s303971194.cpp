#include<bits/stdc++.h>

#define rep(i,n) for(ll i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  double n;cin>>n;
  rep(i,3500)rep(j,3500){
    ll x=i+1;
    ll y=j+1;
    ll z = (n*x*y)/(4*x*y-n*x-n*y);
    if(z<0)continue;
    if(4*x*y*z==n*y*z+n*x*z+n*x*y){
      cout<<x<<' '<<y<<' '<<z;
      return 0;
    }
  }
  
  return 0;
}