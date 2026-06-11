#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const long long MOD = 998244353;

int fact[300010], invfact[300010];

long long powmod(long long a, long long k) {
    int r = 1;
    while(k > 0) {
        if (k & 1) {
            r = (r * a) % MOD;
        }
        a = (a * a) % MOD;
        k /= 2;
    }
    return r;
}

long long invmod(long long a, const long long mod) {
    return powmod(a, mod - 2);
}

const long long comb(long long n, long long i) {
    if (i > n) {
        return 0;
    }
    return (fact[n] * invfact[i]) % MOD * invfact[n-i] % MOD;
}

void solve(long long N, long long A, long long B, long long K){
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < 300010; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = invmod(fact[i], MOD);
    }

    int res = 0;
    for(int i = 0; i <= N; ++i) {
        int L = K - A * i;
        int j = L / B;
        if (L < 0 || L % B != 0 || j > N) {
            continue;
        }
        res += comb(N, i) * comb(N, j) % MOD;
        res %= MOD;
    }
    cout << res << endl;
}

signed main(){
	ios::sync_with_stdio(false);
    long long N;
    scanf("%lld",&N);
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long K;
    scanf("%lld",&K);
    solve(N, A, B, K);
    return 0;
}