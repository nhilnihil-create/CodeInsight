#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=1e9+7;
ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a-=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int c[n];
  rep(i,n) cin >> c[i];
  int n_max=2e5+1;
  int Ind[n_max];
  int nInd[n];
  rep(i,n_max){
    Ind[i]=-1;
    nInd[i]=-1;
  }
  rep(i,n){
    if(Ind[c[i]]==-1){
      Ind[c[i]]=i;
    }
    else {
      nInd[Ind[c[i]]]=i;
      Ind[c[i]]=i;
    }
  }
  ll dp[n+1];
  rep(i,n+1) dp[i]=0;
  dp[0]=1;
  rep(i,n){
    if(nInd[i]==-1 || nInd[i]==i+1){
      dp[i+1] = ad(dp[i+1],dp[i]);
    }
    else{
      dp[nInd[i]] = ad(dp[nInd[i]],dp[i]);
      dp[i+1] = ad(dp[i+1],dp[i]);
    }
  }
  //  rep1(i,n) cout << dp[i] << " ";
  //  cout << "" << endl;
  cout << dp[n] << endl;
  
  return 0;
    

}
