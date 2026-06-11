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

ll N;
vector<vector<int>> a;

//dp
vector<vector<ll>> table;

ll dp(ll n,ll S){
  if(n<0) return 1;
  if(table.at(n).at(S)>-1) return table.at(n).at(S);
  
  ll ret=0;
  rep(i,N){
    if(a.at(n).at(i)&&(S&(1<<i))) ret+=dp(n-1,S&~(1<<i));
  }
  
  return table.at(n).at(S)=ret%MOD;
}
int main()
{
  cin>>N;
  a=vector<vector<int>>(N,vector<int>(N)); rep(i,N) rep(j,N) cin>>a.at(i).at(j);
  
  //dp
  table=vector<vector<ll>>(N,vector<ll>((1<<N),-1));
  
  cout<<dp(N-1,(1<<N)-1)<<endl;
  return 0;
}