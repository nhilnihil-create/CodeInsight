#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
ll mod = 998244353; //素数
const int maxn = 3e5 + 100;
ll fra[maxn];
ll inv[maxn];
ll N,A,B,K;
void exgcd( ll b, ll p, ll & a, ll & k ) {
    if( p == 0 ) {
        a = 1; k = 0;
        return;
    }
    exgcd( p, b % p, k, a );
    k -= b / p * a;
    return;
}
ll INV(ll n){
    ll a,k;
    exgcd(n,mod,a,k);
    if(a < 0)
        a += mod;
    return a;
}
void init(ll n){
    fra[0] = 1;
    for (ll i = 1; i <= n; i++)
        fra[i] = fra[i - 1] * i % mod;
    inv[n] = INV(fra[n]);//快速幂也行
    for (ll i = n - 1; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
ll C(ll up,ll down){
    if(up > down)
        return 0;
    ll ans =  fra[down] * inv[up] % mod * inv[down - up] % mod;
    return ans;
}
int main(){
    cin>>N>>A>>B>>K;
    init(N);
    ll numofA = 0;
    ll ans = 0;
    for (numofA = 0; numofA <= N; numofA++)
    {
        ll sub =  K - numofA * A;
        if(sub < 0)
            break;
        if(sub % B != 0)
            continue;
        ll numofB = sub / B;
        if(numofB > N)
            continue;
        //cout<<numofA <<' '<<numofB<<endl;
        ans = ans + (C(numofA,N) * C(numofB,N)) %mod;
        ans %= mod;
    }
    cout<<ans;
    return 0;
}