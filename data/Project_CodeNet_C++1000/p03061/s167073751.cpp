#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const int MAX = 510000;
const int MOD = 1000000007;

//二項係数ライブラリ
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
long long COM(ll n, ll k) {
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    if (n == k) {
        return 1;
    }
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    vector<int>ansa(N+1);
    vector<int>ansb(N+1);
    int g=0;
    rep(i,N){
        cin>>A[i];
            g=__gcd(g,A[i]);
        	ansa[0]=A[N-1];
        ansa[i+1]=g;
    }
    int gc=0;
    rep(i,N){
            gc=__gcd(gc,A[N-i-1]);
        ansb[i+1]=gc;
    }
      ansb[0]=A[0];
    ll ans=0;
    rep(i,N){
        if(ans<__gcd(ansa[i],ansb[N-i-1])){
            ans=__gcd(ansa[i],ansb[N-i-1]);
        }
    }
    cout<<ans<<endl;
}


