#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll pw(ll x,ll y){
  ll z;
  if(y==0) return 1;
  else{
    z=pw(x,y/2)*pw(x,y/2);
    if(y%2==1) z*=x;
    return z;
  }
}
int main() {
  ll a,b,x,y,i,k,ans=0;
  cin>>a>>b;
  for(i=0;i<50;i++){
    k=pw(2,i);
    y=b/(2*k)*k;
    if(b%(2*k)>=k) y+=b%(2*k)-k+1;
    x=(a-1)/(2*k)*k;
    if((a-1)%(2*k)>=k) x+=(a-1)%(2*k)-k+1;
    if(y==0) break;
    else if((y-x)%2==1) ans+=k;
  }
  cout<<ans<<endl;
}