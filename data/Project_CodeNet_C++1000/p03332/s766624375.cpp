#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 300001;

int n, a, b, fact[N], mod = 998244353;
ll k;

int powlog(int a, int b){
    if(b == 0) return 1;
    int ret = powlog(a, b / 2);
    if(b % 2) return 1LL * ret * ret % mod * a % mod;
    return 1LL * ret * ret % mod;
}
int C(int n, int r){
    return 1LL * fact[n] * powlog(1LL * fact[r] * fact[n - r] % mod, mod - 2) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1 ; i < N ; i++){
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    cin >> n >> a >> b >> k;
    int ans = 0;
    for(int i = 0 ; i <= n ; i++){
        ll g = 1LL * i * a;
        if(g > k || (k - g) % b) continue;
        ll j = (k - g) / b;
        if(j > n) continue;
        ans = (ans + 1LL * C(n, i) * C(n, j)) % mod;
    }
    cout << ans << endl;
}
