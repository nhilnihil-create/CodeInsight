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
  ll N,M; cin>>N>>M;
  vector<vector<ll>> vec(N,vector<ll>(3)); rep(i,N) rep(j,3) cin>>vec[i][j];
  
  ll ans=-INF;
  rep(S,1<<3){
    vector<ll> svec(N);
    rep(i,N){
      ll ele=0;
      rep(j,3){
        if(S&(1<<j)) ele+=vec[i][j];
        else ele-=vec[i][j];
      }
      svec[i]=ele;
    }
    sort(svec.rbegin(),svec.rend());
    ll sans=0;
    rep(i,M) sans+=svec[i];
    chmax(ans,sans);
  }
  
  cout<<ans<<endl;
  return 0;
}