#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<ll,int,int,int,int,int,int,int>T;
#define PI 3.14159265358979
const int MAX = 510000;
const int MOD = 1000000007;
//この設定だとn<10^7が限界。maxの0を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ll N;
  cin>>N;
  ll dp[1000000];
  rep(i,1000000){dp[i]=1000000ll;}
  dp[0]=0ll;
  rep(i,N+1){
  	rep(j,6){
      ll p=i+(ll)pow(6,j+1);
      if(p<=N){dp[p]=min(dp[p],dp[i]+1ll);}
    }
    rep(j,5){
      ll q=i+(ll)pow(9,j+1);
      if(q<=N){dp[q]=min(dp[q],dp[i]+1ll);}
    }
    dp[i+1]=min(dp[i+1],dp[i]+1ll);
  }
  cout<<dp[N];
  
  
} 