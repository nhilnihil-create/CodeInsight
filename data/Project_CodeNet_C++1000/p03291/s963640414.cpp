#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

const int MAX = 510000;
const int MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dp[200020],a[200020],aq[200020],ab[200020],q[200020],qb[200020],p[200020];

int main(){
  COMinit();
  string s;
  cin >> s;
  int n=s.size();
  ll Q=0;
  rep(i,n){
    if(i>0){
      a[i]=a[i-1];
    }
    if(s[i]=='A'){
      a[i]++;
    }
  }
  p[0]=1;
  rep(i,100010){
    p[i+1]=p[i];
    p[i+1]*=3;
    p[i+1]%=mod;
  }
  rep(i,n){
    if(i>0){
      q[i]=q[i-1];
    }
    if(s[i]=='?'){
      q[i]++;
    }
  }
  rep(i,n){
    if(i>0)ab[i]=ab[i-1];
    if(s[i]=='B'){
      ab[i]+=a[i];
      ab[i]%=mod;
    }
  }
  rep(i,n){
    if(i>0)qb[i]=qb[i-1];
    if(s[i]=='B'){
      qb[i]+=q[i];
      qb[i]%=mod;
    }
  }
  rep(i,n){
    if(i>0)aq[i]=aq[i-1];
    if(s[i]=='?'){
      aq[i]+=a[i];
      aq[i]%=mod;
    }
  }
  for(int i=2;i<n;i++){
    if(s[i]=='A' || s[i]=='B')dp[i]=dp[i-1];
    else if(s[i]=='C' || s[i]=='?'){
      if(s[i]=='C')dp[i]=dp[i-1];
      if(s[i]=='?')dp[i]=(3*dp[i-1])%mod;
      dp[i]%=mod;
      dp[i]+=(ab[i-1]*p[q[i-1]])%mod;
      dp[i]%=mod;
      if(q[i-1]-1>=0)dp[i]+=(p[q[i-1]-1]*aq[i-1])%mod;
      dp[i]%=mod;
      if(q[i-1]-1>=0)dp[i]+=(p[q[i-1]-1]*qb[i-1])%mod;
      dp[i]%=mod;
      if(q[i-1]>=2)dp[i]+=(COM(q[i-1],2)*p[q[i-1]-2])%mod;
      dp[i]%=mod;
    }
  }
  cout << dp[n-1] << endl;
return 0;}