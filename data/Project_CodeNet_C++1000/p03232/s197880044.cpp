#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll n){
    ll res = 1;
    ll r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

ll r[100002];

int main()
{
    int n;
    cin >> n;
    ll a[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) r[i] = (r[i - 1] + modpow(i, MOD - 2)) % MOD;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + a[i] * ((r[i + 1] + r[n - i] + MOD - 1) % MOD) % MOD) % MOD;
    }
    for(int i = 1; i <= n; i++) ans = ans * i % MOD;
    cout << ans << endl;
}