#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;

int fact[300010];

int myPow(int a, int r){
    if(r == 0) return 1;
    int half = myPow(a, r / 2);
    if(r & 1) return half * 1ll * half % mod * a % mod;
    else return half * 1ll * half % mod;
}

int comb(int n, int r){
    return fact[n] * 1ll * myPow(fact[r], mod - 2) % mod * myPow(fact[n - r], mod - 2) % mod;
}

int main(){
    int n, a, b, ans = 0;
    ll k;
    cin >> n >> a >> b >> k;

    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * 1ll * i % mod;

    for(int x = 0; x <= n; x++){
        ll left = (k - a * 1ll * x);
        if(left % b != 0) continue;
        ll y = left / b;
        if(y > n || y < 0) continue;

        ans = (ans + comb(n, x) * 1ll * comb(n, y)) % mod;
    }
    cout << ans << endl;
    return 0;
}