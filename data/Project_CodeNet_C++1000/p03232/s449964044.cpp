#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

int N;

//1!~N!を計算
vector<ll> Factorial(){
    vector<ll> v{1}; //0!
    ll f = 1;
    for(ll i = 1; i <= N; ++i){
        f *= i;
        f %= MOD;
        v.push_back(f);
    }
    return v;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(void){
    
    scanf("%d", &N);
    auto fact = Factorial();
    
    vector<ll> inv(100001, 0);
    for(int i = 1; i <= N; i++){
		inv[i] = (inv[i - 1] + modinv(i, MOD)) % MOD;
	}
	
    ll ans = 0;
    for(int i = 1; i <= N; ++i){
        ll a; scanf("%lld", &a);
        ans += a * ((inv[i] + inv[N - i + 1]) - 1) % MOD;
        ans %= MOD;
    }
    
    printf("%lld\n", (ans * fact[N]) % MOD);
    
    return 0;
}