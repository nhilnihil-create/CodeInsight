#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

const int MAX_N = 300005;

ll fmemo[MAX_N + 3];
ll imemo[MAX_N + 3];
ll ifmemo[MAX_N + 3];

ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

ll fact(ll n){
    if(n == 0) return 1;
    if(fmemo[n]) return fmemo[n];
    return fmemo[n] = n * fact(n - 1) % MOD;
}

ll ifact(ll n){
    if(n == 0) return 1;
    if(ifmemo[n]) return ifmemo[n];
    return ifmemo[n] = imemo[n] * ifact(n - 1) % MOD;
}

ll com(ll n, ll k){
    if(k > n) return 0;
    if(k < 0) return 0;
    if(k == n || k == 0) return 1;
    return (fact(n) * ifact(k) % MOD) * ifact(n - k) % MOD;
}

int main()
{
    for(ll i = 1; i <= MAX_N; i++){
        imemo[i] = modpow(i, MOD - 2);
    }
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        if((k - a * i) % b == 0){
            int j = (k - a * i) / b;
            ans += com(n, i) * com(n, j) % MOD;
        }
    }
    cout << ans % MOD << endl;
}