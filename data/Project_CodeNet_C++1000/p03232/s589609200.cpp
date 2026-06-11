#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int MN = 100010;

int exp(int x, int n) {
    int ret = 1;
    while(n) {
        if(n & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
        n >>= 1;
    }
    return ret;
}
int inv(int x) {
    return exp(x, mod - 2);
}
int fact[MN], invf[MN];
int comb(int n, int k) {
    return 1LL * fact[n] * invf[k] % mod * invf[n - k] % mod;
}

int N;
int A[MN], psum[MN];

int main() {
    fact[0] = 1;
    for(int i = 1; i < MN; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    for(int i = 0; i < MN; i++) {
        invf[i] = inv(fact[i]);
    }

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 1; i <= N; i++) {
        psum[i] = 1LL * fact[i] * fact[N - i - 1] % mod * comb(N, i + 1) % mod;
        psum[i] += psum[i - 1];
        psum[i] %= mod;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += 1LL * A[i] * (psum[i] + psum[N - 1 - i]) % mod;
        ans %= mod;
        ans += 1LL * A[i] * fact[N] % mod;
        ans %= mod;
    }
    printf("%d", ans);
}
