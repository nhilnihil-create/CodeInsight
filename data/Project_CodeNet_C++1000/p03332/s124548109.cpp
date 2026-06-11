#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 300005;
const int MOD = 998244353;

ll ADD(ll a, ll b){
    return (a+b)%MOD;
}
ll MUL(ll a, ll b){
    return a*b%MOD;
}
ll EXP(ll b, int e){
    if(e==0) return 1;
    if(e%2) return MUL(b, EXP(b, e-1));
    else return EXP(MUL(b, b), e/2);
}
ll DIV(ll a, ll b){
    return MUL(a, EXP(b, MOD-2));
}
ll f[MAXN];
ll C(ll n, ll k){
    return DIV(f[n], MUL(f[k], f[n-k]));
}



int main(){
    f[0]=1;
    for(int i=1;i<MAXN;++i) f[i]=MUL(f[i-1], i);
    ll n, a, b, k, sol=0;
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    if(a<b) swap(a,b );

    if(b==0){
        if(a==0){
            puts((k==0?"1":"0"));
        }else{
            if(k%a==0) puts("1");
            else puts("0");
        }
        return 0;
    }
    for(ll i=0;i<=n;++i){
        if(i*a<=k && (k-i*a)%b==0 && (k-i*a)/b<=n){
            sol = ADD(sol, MUL(C(n, i), C(n, (k-i*a)/b)));
        }
    }
    printf("%lld\n", sol);
}
