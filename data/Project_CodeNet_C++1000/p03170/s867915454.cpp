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
ll N,K;

//dp
vector<bool> table;
vector<bool> checked;

bool dp(ll k){
  if(k<a.at(0)) return false;
  if(checked.at(k)) return table.at(k);
  
  checked.at(k)=true;
  rep(i,N){
    if(k-a.at(i)>=0&&!dp(k-a.at(i))) table.at(k)=true;
  }
  
  return table.at(k);
}

int main()
{
  cin>>N>>K;
  a=vector<ll>(N); rep(i,N) cin>>a.at(i);
  sort(a.begin(),a.end());
  
  //dp
  table=vector<bool>(K+1,false);
  checked=vector<bool>(K+1,false);
  
  if(dp(K)) cout<<"First"<<endl;
  else cout<<"Second"<<endl;
  return 0;
}