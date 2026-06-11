#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,K,count=0,check=0;
  cin>>N>>K;
  vector<ll> A(0);
  unordered_map<ll,ll> mp;
  for(ll i=0;i<N;i++){
    ll a;
    cin>>a;
    if(mp[a]==0){check++;A.push_back(a);}
    mp[a]++;
  }
  ll d=A.size();
  if(check<=K){cout<<0<<endl;return 0;}
  for(ll i=1;i<=N;i++){
    ll rock=0;
    for(ll j=0;j<d;j++){
      if(mp[A.at(j)]==i){mp[A.at(j)]=0;count+=i;check--;}
      if(K>=check){rock=1;break;}
    }
    if(rock==1){break;}
  }
  cout<<count<<endl;
}