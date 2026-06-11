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
  ll L[M],R[M];
  rep(i,M) cin>>L[i]>>R[i];
  ll mi=1;
  ll ma=N;
  for(int i=0;i<M;i++){
    mi=max(mi,L[i]);
    ma=min(ma,R[i]);
  }
  ll ans=0;
  if(mi<=ma) ans=ma-mi+1;
  cout<<ans<<endl;
}
