#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//a^n (mod m)
const long long mod = 1e9+7;
long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

//mod mでの a の逆元を求める
long long modinv(long long a) {
    long long b = mod, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod; 
    if (u < 0) u += mod;
    return u;
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll p[n]={};
    p[0] = modinv(1);
    for(int i=1;i<n;i++){
        p[i] = p[i-1] + modinv(i+1);
        p[i] %= mod;
    }

    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += (a[i] * ((p[i-0] + p[n-1 - i]+mod - 1)%mod))%mod;
        ans %= mod;
    }
    for(int i=1;i<=n;i++){
        ans *= i;
        ans %= mod;
    }
    cout<<ans<<endl;
    
}
