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



int main()
{
  ll N,M; cin>>N;
  vector<string> s(N); rep(i,N) cin>>s[i];
  cin>>M;
  vector<string> t(M); rep(i,M) cin>>t[i];
  
  map<string,ll> mp;
  for(auto str:s){
    if(!mp.count(str)) mp[str]=1;
    else mp.at(str)++;
  }
  for(auto str:t){
    if(!mp.count(str)) mp[str]=-1;
    else mp.at(str)--;
  }
  
  ll ans=0;
  for(auto p:mp){
    string str; ll mon; tie(str,mon)=p;
    chmax(ans,mon);
  }
  
  cout<<ans<<endl;
  return 0;
}