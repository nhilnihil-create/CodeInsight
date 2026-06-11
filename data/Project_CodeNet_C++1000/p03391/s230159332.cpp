#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int main(){
  ll n;cin>>n;
  ll a[n],b[n];
  vector<pll>v;
  ll ans=0;
  for(ll i=0;i<n;i++){
    cin>>a[i]>>b[i];
    ans+=a[i];
    if(a[i]>b[i]){
      v.push_back(make_pair(b[i],i));
    }
  }
  if(v.size()==0){
    cout<<0<<endl;
    return 0;
  }
  sort(v.begin(),v.end());
  ans-=b[v[0].second];
  cout<<ans<<endl;
}