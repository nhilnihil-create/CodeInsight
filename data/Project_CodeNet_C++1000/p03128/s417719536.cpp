
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
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
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
  ll N,M;
  cin>>N>>M;
  vector<ll>A(M);
  ll use[10]={0,2,5,5,4,5,6,3,7,6};
  rep(i,M){
  	cin>>A[i];
  } 
  string dp[11000];
  rep(i,11000){dp[i]="-";}
  dp[0]="";
  for(int i=0;i<=10000;i++){
    if(dp[i]=="-"){continue;}
  	for(auto a:A){
      ll p=dp[i+use[a]].size(),q=dp[i].size();q++;
      if(dp[i+use[a]]=="-"){dp[i+use[a]]=dp[i]+(char)(a+'0');continue;}
      if(p<q){
      	dp[i+use[a]]=dp[i]+(char)(a+'0');
      }
      else if(p==q){
      	dp[i+use[a]]=max(dp[i]+(char)(a+'0'),dp[i+use[a]]);
      }
    }
  }
  cout<<dp[N];
} 
