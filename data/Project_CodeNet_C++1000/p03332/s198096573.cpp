#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
const ll MAX = 310000;
const ll MOD = 998244353;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
void Main(){
    ll n,a,b,k,ans = 0;
    cin >> n >> a >> b >> k;
    For(i,0,n+1){
        if((k-i*a)%b==0 && (k-i*a)/b>=0 && (k-i*a)/b<=n){
            ans += COM(n,i) * COM(n,(k-i*a)/b) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
int main(){
    COMinit();
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}