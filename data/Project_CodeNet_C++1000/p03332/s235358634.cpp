#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=998244353;

const ll MAX = 1000000;
ll fac[MAX], finv[MAX], inv[MAX];
// nCk初期化
void nCkInit(const ll MOD) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll nCk(ll n, ll k,const ll MOD){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll N,A,B,K;
int main(){
    cin>>N>>A>>B>>K;
    nCkInit(MOD);
    ll ans=0;
    for(ll aNum=0;aNum*A<=K && aNum<=N;aNum++){
        if((K-aNum*A)%B!=0)continue;
        ll bNum=(K-aNum*A)/B;
        if(aNum>N || bNum>N)continue;
        ans=(ans+nCk(N,aNum,MOD)*nCk(N,bNum,MOD)%MOD)%MOD;
    }
    cout<<ans;
    return 0;
}