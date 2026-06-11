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

vector<ll> a;
ll dp(ll,ll); ll sdp(ll,ll);

//dp
vector<vector<ll>> table;

ll dp(ll n,ll k){
  if(k<0) return 0;
  if(k==0) return 1;
  if(n<0) return 0;
  if(n==0){
    if(a.at(n)>=k) return 1;
    else return 0;
  }
  if(table.at(n).at(k)>-1) return table.at(n).at(k);
  
  table.at(n).at(k)=sdp(n-1,k+1)-sdp(n-1,max((int)(k-a.at(n)),0));
  if(table.at(n).at(k)<0) table.at(n).at(k)+=MOD;
  
  return table.at(n).at(k);
}

//sdp
vector<vector<ll>> stable;

ll sdp(ll n,ll k){
  if(k==0) return 0;
  if(stable.at(n).at(k)>-1) return stable.at(n).at(k);
  
  return stable.at(n).at(k)=(sdp(n,k-1)+dp(n,k-1))%MOD;
}
  
int main()
{
  ll N,K; cin>>N>>K;
  a=vector<ll>(N); rep(i,N) cin>>a.at(i);
  
  //dp
  table=vector<vector<ll>>(N,vector<ll>(K+1,-1));
  //sdp
  stable=vector<vector<ll>>(N,vector<ll>(K+2,-1));
  
  cout<<dp(N-1,K)<<endl;
  /*
  rep(i,N){
    rep(j,K+1){
      if(j!=0) cout<<" ";
      cout<<dp(i,j);
    }
    cout<<endl;
  }
  */
  
  return 0;
}