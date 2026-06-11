//https://atcoder.jp/contests/abc100/tasks/abc100_d
//D - Patisserie ABC
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
  ll N,M; cin>>N>>M;
  struct info{
    array<ll,3> xyz;
    ll id;
  };
  vector<info> infon(N);
  REP(n,N){
    auto&& i=infon.at(n);
    cin>>i.xyz[0]>>i.xyz[1]>>i.xyz[2];
    i.id=n;
  }

  ll ans=0;
  ll bit_max=1<<3;
  FOR(m,0,bit_max){
    using pa=pair<ll,ll>; //value,id
    vector<pa> lst(N);
    REP(i,N){
      const auto& info=infon.at(i);
      auto&& l=lst.at(i);
      FOR(i,0,3){
        ll sig=m&(1<<i)?-1:1;
        l.first += (info.xyz[i]*sig);
      }
      l.second=i;
    }
    sort(lst.begin(),lst.end());
    reverse(lst.begin(),lst.end());
    //value
    ll x=0,y=0,z=0;
    REP(i,M){
      auto id= lst.at(i).second;
      const auto & info=infon.at(id);
      x+=info.xyz[0];
      y+=info.xyz[1];
      z+=info.xyz[2];
    }
    chmax(ans,abs(x)+abs(y)+abs(z));
  }
  cout<<ans<<endl;

  return 0;
}