// A

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll MOD=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

const int MAX = (int)1e6;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
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
 // 二項係数計算
 long long COM(int n, int k){  //nCkの計算をする
     if (n < k) return 0;
     if (n < 0 || k < 0) return 0;
     return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
 }
 //main関数にCOMinit();を忘れない

int main(){
  COMinit();
  ll N,K;
  cin>>N>>K;
  ll ans(0);
  if (K&1){
    cout << (N / K)*(N/K)*(N/K) << endl;
  }else{
    ans += (N/K)*(N/K)*(N/K);
    ll cnt(0);
    for (int i(1);i<=N;i++){
      if (i%K == K/2){
        cnt++;
      }
    }
    //cout << cnt << endl;
    ans += cnt*cnt*cnt;
    cout << ans << endl;
  }
  return 0;
}

