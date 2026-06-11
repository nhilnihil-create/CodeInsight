#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,p;cin>>n>>p;
  if(n==1){
    cout<<p<<endl;
    return 0;
  }
  ll ans=1;
  for(ll i=2;;i++){
    if(pow(i,n)>p)break;
    ll num=pow(i,n);
    if(p%num==0)ans=i;
  }
  cout<<ans<<endl;
}
