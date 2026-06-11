#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N,M;
  cin>>N>>M;
  bool love[N][M];
  rep(i,N){
    rep(j,M){
      love[i][j]=false;
    }
  }
  rep(i,N){
    ll K;
    cin>>K;
    ll a[K];
    rep(j,K){
      cin>>a[j];
      love[i][a[j]-1]=true;
    }
  }
  bool total_love[M];
  rep(i,M) total_love[i]=true;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!love[i][j]){
        total_love[j]=false;
      }
    }
  }
  ll ans=0;
  for(int i=0;i<M;i++){
    if(total_love[i]) ans++;
  }
  cout<<ans<<endl;
  
}