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
  ll ans=0;
  for(ll p=1;p*p<N;p++){
    if(N%p!=0) continue;
    ll m=N/p-1;
    if(p<m) ans+=m;
  }
  cout<<ans<<endl;
  return 0;
}