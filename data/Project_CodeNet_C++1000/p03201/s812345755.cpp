#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=174417441744;
ll pw(ll k){
  for(int i=0;i<40;i++){
    if((((ll)1)<<i)>k) return (((ll)1)<<i);
  }
}
int main(){
  multiset<ll> ms,ms_;
  ll n;
  cin>>n;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    ms.insert(a);
    ms_.insert(-a);
  }
  ll ans=0;
  while(!ms.empty()){
    ll max_v=*(ms_.upper_bound(-inf));
    max_v*=-1;
    ll pr=pw(max_v)-max_v;
    ms.erase(ms.find(max_v));
    ms_.erase(ms_.find(-max_v));
    if(ms.empty()) break;
    ll ai=*(ms.lower_bound(pr));
    if(ai==pr){
      ans++;
      ms.erase(ms.find(ai));
      ms_.erase(ms_.find(-ai));
    }
  }
  cout<<ans<<endl;
}
