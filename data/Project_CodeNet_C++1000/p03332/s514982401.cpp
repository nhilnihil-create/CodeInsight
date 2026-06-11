#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

const ll MAX = 1000000;
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

ll n,a,b,k,ans;

int main(){
    COMinit();
    cin>>n>>a>>b>>k;
    for(ll i=0;i*a<=k;i++){
        if((k-a*i)%b)continue;
        ll j=(k-a*i)/b;
        (ans+=COM(n,i)*COM(n,j))%=MOD;
    }
    cout<<ans<<endl;
}