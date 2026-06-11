#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

// i*a + j*b + k*(a+b) = (i+k)*a + (j+k)*b = x

constexpr ll mod = 998244353;
#define NMAX 300010
ll fac[NMAX];
ll inv[NMAX];

ll mod_pow(ll a, ll n, ll mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret*(a % mod))%mod;
        a = ((a%mod)*(a%mod)) % mod;
        n = n >> 1;
    }
    return ret;
}

ll mod_inv(ll a, ll mod){
    return mod_pow(a, mod-2, mod);
}

void mae_nck(){
    fac[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i < NMAX; i++){
        fac[i] = (fac[i-1] * i)%mod;
        inv[i] = (inv[i-1] * mod_inv(i, mod))%mod;
    }
}

ll mod_nck(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if(k == 0 || k == n) return 1;
    ll ret = ((fac[n] * inv[k])%mod * inv[n-k])%mod;
    return ret;
}

int main(){
    mae_nck();

    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    // a * i + b * j = k とすると，i を固定したときに，j = (k - a*i) / b
    // もちろん，割り切れる必要がある
    // ここで，r, g, b について，次のことが言える
    // r + g = i, b + g = j 
    // となると，r, g, b について，nCr x nCb で答えを導出できる

    ll ans = 0;
    rep(i, 0, n+1){
        if((k - a*i) % b != 0) continue;
        ll j = (k - a*i) / b;
        ans += (mod_nck(n, i) * mod_nck(n, j)) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}