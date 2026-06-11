#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

const ll INF=1e18;

ll mult(ll a,ll b){
  if(b==0) return 0;
  if((a*b)/b!=a) return INF;
  return (a*b);
}

int main(){
  int N;
  ll X;
  cin>>N>>X;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  vector<ll> sum(N+1,0);
  for(int i=0;i<N;i++) sum[i+1]=sum[i]+A[i];

  ll ans=INF;
  for(int k=1;k<=N;k++){
    ll coef=5;
    ll res=mult(coef,sum[N]-sum[N-k]);
    res+=mult(k,X);
    for(int i=N-k;i>=0;i-=k){
      res+=mult(coef,sum[i]-sum[max(0,i-k)]);
      res=min(res,INF);
      coef+=2;
    }
    ans=min(ans,res);
  }

  cout<<ans+N*X<<endl;

  return 0;
}
