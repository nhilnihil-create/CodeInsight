#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<pair<int,ll>>>;
using pp=pair<ll,pair<ll,ll>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 1000000000000000000

ll modpow(ll a,ll n,ll mod){
  ll res=1;
  while(n>0){
    if(n&1){       //nのbitと...00001を比較  nが2で割り切れるならtrue
      res=(res*a)%mod;
    }
    a=(a*a)%mod;
    n>>=1;
  }
  return res;
}

ll modinv(ll a,ll mod){
  return modpow(a,mod-2,mod);
}

int main(){
  string S;
  cin>>S;
  int N=S.size();
  vector<vector<ll>> count(N+1,vector<ll>(4,0));
  for(int i=0;i<N;i++){
    for(int j=0;j<4;j++){
      count[i+1][j]=count[i][j];
    }
    if(S[i]=='A'){
      count[i+1][1]++;
    }else if(S[i]=='B'){
      count[i+1][2]++;
    }else if(S[i]=='C'){
      count[i+1][3]++;
    }else{
      count[i+1][0]++;
    }
  }

  ll Q=count[N][0];
  ll num1=modpow(3,Q,MOD);
  ll num2=modpow(3,Q-1,MOD);
  ll num3=modpow(3,Q-2,MOD);
  ll num4=modpow(3,Q-3,MOD);

  ll ans=0;
  for(int i=0;i<N;i++){
    ll x;
    if(S[i]=='B'){
      x=count[i][1]*(count[N][3]-count[i+1][3])%MOD;
      ans+=x*num1%MOD;
      ans%=MOD;

      x=count[i][1]*(count[N][0]-count[i+1][0])%MOD;
      ans+=x*num2%MOD;
      ans%=MOD;

      x=count[i][0]*(count[N][3]-count[i+1][3])%MOD;
      ans+=x*num2%MOD;
      ans%=MOD;

      x=count[i][0]*(count[N][0]-count[i+1][0])%MOD;
      ans+=x*num3%MOD;
      ans%=MOD;
    }else if(S[i]=='?'){
      x=count[i][1]*(count[N][3]-count[i+1][3])%MOD;
      ans+=x*num2%MOD;
      ans%=MOD;

      x=count[i][0]*(count[N][3]-count[i+1][3])%MOD;
      ans+=x*num3%MOD;
      ans%=MOD;

      x=count[i][1]*(count[N][0]-count[i+1][0])%MOD;
      ans+=x*num3%MOD;
      ans%=MOD;

      x=count[i][0]*(count[N][0]-count[i+1][0])%MOD;
      ans+=x*num4%MOD;
      ans%=MOD;
    }
  }

  cout<<ans<<endl;
}
