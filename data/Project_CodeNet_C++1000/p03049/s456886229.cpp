#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N; cin>>N;
  vector<string> vec(N); rep(i,N) cin>>vec[i];
  
  ll ans=0;
  ll numB=0,numA=0,numBA=0;
  for(auto str:vec){
    ll n=str.size();
    rep(i,n-1) if(str.substr(i,2)=="AB") ans++;
    if(str[0]=='B'&&str[n-1]=='A') {numBA++; continue;}
    if(str[0]=='B') numB++;
    if(str[n-1]=='A') numA++;
  }
  ll alpha=max(numBA-1,(ll)0);
  if(numBA>0){
    if(numA>0) {alpha++; numA--;}
    if(numB>0) {alpha++; numB--;}
  }
  alpha+=min(numA,numB);
  
  cout<<ans+alpha<<endl;
  
  return 0;
}