#include <stdio.h>
#define fin freopen("in.txt", "r", stdin);
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 1e5+5;
ll fac[maxn];
ll quick_mod(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int n;
void pre_hand(){
    //预处理
    for(ll i = 1; i <= n; i++){
        fac[i] = (fac[i-1] + quick_mod(i, mod-2)) % mod;  //预处理1/1+1/2+...1/i的前缀和 
    }
}

int main(){
   // fin;
    scanf("%d", &n);
    pre_hand();
    ll x, res = 1, ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &x);
        ans = (ans + x * (fac[i] + fac[n-i+1] - 1 + mod) % mod) % mod;
        (res *= i) %= mod;    //res最终结果是n!
    }
    printf("%lld\n", ans * res % mod);
}