#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<vector<ll>> graph;

//dp
vector<vector<ll>> table;
vector<ll> checked;

ll dp(ll sep,ll v){
  //cout<<sep<<" "<<v<<endl;
  if(table.at(sep).at(v)>-1) return table.at(sep).at(v);
  
  ll ret=1;
  if(sep==0){
    for(auto nv:graph.at(v)){
      if(nv==checked.at(v)) continue;
      checked.at(nv)=v;
      ret=ret*(dp(0,nv)+dp(1,nv))%MOD;
    }
  }
  else{
    for(auto nv:graph.at(v)){
      if(nv==checked.at(v)) continue;
      checked.at(nv)=v;
      ret=ret*dp(0,nv)%MOD;
    }
  }
  
  return table.at(sep).at(v)=ret;
}

int main()
{
  ll N; cin>>N;
  graph=vector<vector<ll>>(N,vector<ll>(0));
  rep(i,N-1){
    ll x,y; cin>>x>>y; x--; y--;
    graph.at(x).push_back(y);
    graph.at(y).push_back(x);
  }
  
  //dp
  table=vector<vector<ll>>(2,vector<ll>(N,-1));
  checked=vector<ll>(N,-1);
  
  cout<<(dp(0,0)+dp(1,0))%MOD<<endl;
  
  return 0;
}