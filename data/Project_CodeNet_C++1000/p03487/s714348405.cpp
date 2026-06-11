#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  map<ll,ll> mapa;
  rep(i,N)
  {
    ll a; cin>>a;
    if(mapa.count(a)) {mapa.at(a)++; continue;}
    mapa[a]=1;
  }
  ll count=0;
  for(auto p:mapa)
  {
    if(p.first<p.second) {count+=p.second-p.first; continue;}
    if(p.first>p.second) {count+=p.second;}
  } 
  cout<<count<<endl;
  return 0;
}