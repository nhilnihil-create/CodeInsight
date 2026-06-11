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
vector<ll> sum;

//dp
vector<vector<ll>> table;

ll dp(ll i,ll j){
  if(j-i==1) return 0;
  if(table.at(i).at(j)<INF) return table.at(i).at(j);
  
  ll ret=INF;
  for(int k=i+1;k<j;k++){
    chmin(ret,dp(i,k)+dp(k,j)+sum.at(k)-sum.at(i)+sum.at(j)-sum.at(k));
  }
  
  return table.at(i).at(j)=ret;
}

int main()
{
  ll N; cin>>N;
  a=vector<ll>(N); rep(i,N) cin>>a.at(i);
  
  //累積和
  sum=vector<ll>(N+1,0); rep(i,N) sum.at(i+1)=sum.at(i)+a.at(i);
  
  //dp
  table=vector<vector<ll>>(N,vector<ll>(N+1,INF));
  
  cout<<dp(0,N)<<endl;
  return 0;
}