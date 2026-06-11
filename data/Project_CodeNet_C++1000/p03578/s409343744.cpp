#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N; cin>>N;
  map<ll, ll> mpa;
  for(ll i=0; i<N; i++){
    ll D; cin>>D;
    if(mpa.count(D)) mpa[D]++;
    else mpa[D]=1;
  }
  ll M; cin>>M;
  map<ll, ll> mpb;
  for(ll i=0; i<M; i++){
    ll T; cin>>T;
    if(mpb.count(T)) mpb[T]++;
    else mpb[T]=1;
  }
  bool dame=0;
  for(auto p : mpb){
    auto k=p.first;
    auto v=p.second;
    if(mpb[k]>mpa[k]) dame=1;
  }
  if(dame) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}