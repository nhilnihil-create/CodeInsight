#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long ruiseki[100005];
long long A[100005];

int main(void) {
    COMinit();
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ruiseki[i] = (fac[N] * inv[i]) % MOD + ruiseki[i-1];
        ruiseki[i] %= MOD;
    }
    
    for (int i = 0; i < N; i++) {
        ans += A[i] * ruiseki[N - i] % MOD;
        ans %= MOD;
        ans += A[i] * (ruiseki[i+1] - ruiseki[1] + MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
