#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;
using ll=long long;

int main(){
  ll N; cin>>N;
  map<ll, ll> A;
  for(ll i=0; i<N; i++){
    ll a; cin>>a;
    if(A.count(a)) A[a]++;
    else A[a]=1;
  }
  ll ans=0;
  for(auto p:A){
    auto k=p.first;
    auto v=p.second;
    if(v<k) ans+=v;
    else if(v>=k) ans+=(v-k);
  }
  cout<<ans<<endl;
}