#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
  ll q;
  cin>>q;
  for(ll i=0;i<q;i++){
    ll a,b;
    cin>>a>>b;
    if(a==1&&b==1){
      cout<<0<<endl;
      continue;
    }
    if(a<b) swap(a,b);
    ll ans=b-1,lb=0,rb=a-1,sk=a*b-1;
    while(rb-lb>1){
      ll mid=(lb+rb)/2;
      if(mid*mid+mid<=sk){
        lb=mid;
      }
      else rb=mid;
    }
    ans+=lb;
    ans+=(sk/rb)-b;
    cout<<ans<<endl;
  }
}
