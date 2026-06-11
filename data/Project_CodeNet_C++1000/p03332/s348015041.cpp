#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

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

struct Combination
{
    int maxn;
    vector<ll> fmemo;
    vector<ll> imemo;
    vector<ll> ifmemo;
    
    Combination(int maxn) : maxn(maxn){
        fmemo.resize(maxn + 1);
        imemo.resize(maxn + 1);
        ifmemo.resize(maxn + 1);
        for(ll i = 1; i <= maxn; i++){
            imemo[i] = modpow(i, MOD - 2);
        }
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
        if(k == n || k == 0) return 1;
        return (fact(n) * ifact(k) % MOD) * ifact(n - k) % MOD;
    }
};

int main()
{
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    Combination com(n + 1);
    for(int i = 0; i <= n; i++){
        if(k - a * i >= 0 && (k - a * i) % b == 0){
            int j = (k - a * i) / b;
            if(j > n) continue;
            ans = (ans + com.com(n, i) * com.com(n, j) % MOD) % MOD;
        }
    }
    cout << ans << endl;
}
