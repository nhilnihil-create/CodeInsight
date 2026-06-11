#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;
//const ll MOD=998244353;

ll sum[1010];

int main(){
  int N,K; cin>>N>>K;
  rep(i,N){
    ll A; cin>>A;
    sum[i+1]=sum[i]+A;
  }
  vector<ll> V;
  for(int i=1;i<=N;i++) for(int j=i;j<=N;j++){
    V.push_back(sum[j]-sum[i-1]);
  }
  for(int i=45;i>=0;i--){
    vector<ll> tmp;
    for(ll v:V){
      if((1LL<<i)&v) tmp.push_back(v);
    }
    if(tmp.size()>=K) V=tmp;
  }
  ll ans=V[0];
  rep(i,K-1) ans=ans&V[i+1];
  cout<<ans<<endl;
  return 0;
}