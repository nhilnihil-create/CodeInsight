#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int MOD= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
ll mod=998244353;
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
    ll n,a,b,k;
    cin >>n>>a>>b>>k;
    COMinit();
    ll ans=0;
    for (int i = 0; i <=n; ++i) {
        if((k-a*i)%b==0){
            ll j=(k-a*i)/b;
            ans+=(COM(n,i)*COM(n,j))%mod;
        }
        ans%=mod;
    }
    cout <<ans <<endl;
    return 0;
}