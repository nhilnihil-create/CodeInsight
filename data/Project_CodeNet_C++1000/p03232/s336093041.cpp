#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;

int n, fact[N], inv[N], s[N], mod = 1e9 + 7;
vector <int> a;

int powlog(int a, int b){
    if(b == 0) return 1;
    int ret = powlog(a, b / 2);
    if(b % 2) return 1LL * ret * ret % mod * a % mod;
    return 1LL * ret * ret % mod;
}
int calc(int m){
    return 1LL * s[m] * fact[n] % mod * inv[m] % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1 ; i < N ; i++){
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    inv[N - 1] = powlog(fact[N - 1], mod - 2);
    for(int i = N - 2 ; i >= 0 ; i--){
        inv[i] = 1LL * (i + 1) * inv[i + 1] % mod;
    }
    for(int i = 1 ; i < N ; i++){
        s[i] = (1LL * i * s[i - 1] + fact[i - 1]) % mod;
    }
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans = (ans + 1LL * a[i] * (calc(i + 1) + calc(n - i)) % mod) % mod; 
        ans = (ans - 1LL * a[i] * fact[n] % mod + mod) % mod;
    }
    cout << ans << endl;
}
