#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll>a(N);
  for(ll i=0;i<N;i++)cin>>a[i];

  vector<ll>s(N+1,0);
  map<ll,ll>mp;
  for(ll i=0;i<N;i++){
    s[i+1]=s[i]+a[i];
  }
  for(int i=0;i<N+1;i++){
    mp[s[i]]++;
  }
  ll ans=0;
  for(auto t:mp){
    ll x=t.second;
    ans+=x*(x-1)/2;
  }
  cout<<ans<<endl;
}
