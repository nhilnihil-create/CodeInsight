#include<bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int mod = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}

int main(){
    long long n,a,b,k;
    cin>>n>>a>>b>>k;
    long long ans=0;
    COMinit();
    for(long long red=0;red<=n;red++){
        long long m=k-a*red;
        if(m%b!=0) continue;
        long long blue=m/b;
        ans+=COM(n,red)*COM(n,blue);
        ans%=mod;

    }
    cout<<ans<<endl;
    
}