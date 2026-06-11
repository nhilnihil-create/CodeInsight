#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll q;cin>>q;
  for(ll i=0;i<q;i++){
    ll a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    ll ans=a-1;
    ll l=pow(a*b,0.5);
    if(l*(l+1)<a*b)l++;
    //if(i==5){cout<<l<<" "<<r;return 0;}
    if(l>=b){
      ll u=(a*b)/(a+1);
      if((a*b)%(a+1)==0)u--;
      ans+=u;
    }
    else{
      ans+=l-1;
      ll u=(a*b)/l;
      if((a*b)%l==0)u--;
      ans+=max(u-a,(ll)0);
    }
    cout<<ans<<endl;
  }
}