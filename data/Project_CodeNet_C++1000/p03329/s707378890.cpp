#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<ll> table;

ll dp(ll n)
{
  if(n==0) return 0;
  if(table.at(n)<INF) return table.at(n);
  chmin(table.at(n),dp(n-1)+1);
  for(int i=1;i<=7;i++)
  {
    if(n-pow(6,i)>=0) chmin(table.at(n),dp(n-pow(6,i))+1);
  }
  for(int i=1;i<=6;i++)
  {
    if(n-pow(9,i)>=0) chmin(table.at(n),dp(n-pow(9,i))+1);
  }
  
  return table.at(n);
}  
  

int main() 
{
  ll N; cin>>N;
  table=vector<ll>(N+1,INF);
  //table.at(0)=0;
  cout<<dp(N)<<endl;
  return 0;
}