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
  ll N,M; cin>>N>>M;
  vector<pair<ll,ll>> vec(N+M);
  rep(i,N) {
    ll A; cin>>A;
    vec[i]={A,1};
  }
  for(int i=N;i<N+M;i++){
    ll B,C; cin>>B>>C;
    vec[i]={C,B};
  }
  
  sort(vec.rbegin(),vec.rend());
  ll sum=N,ans=0;
  for(auto p:vec){
    ll B,C; tie(C,B)=p;
    ans+=C*min(B,sum);
    sum-=B;
    if(sum<=0) break;
  }
  
  cout<<ans<<endl;
  
  return 0;
}