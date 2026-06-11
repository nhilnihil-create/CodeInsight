#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll MOD = 1000000007;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1LL;
    if (n % 2 == 1) return a * mod_pow(a, n-1) % MOD;
    ll h = mod_pow(a, n/2);
    return h * h % MOD;
}

ll fact[101010], inv[101010], sum_inv[101010];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 101010; ++i)
        fact[i] = i * fact[i-1] % MOD;

    inv[0] = 0;
    for (int i = 1; i < 101010; ++i) {
        inv[i] = mod_pow(i, MOD-2);
        sum_inv[i] = (sum_inv[i-1] + inv[i]) % MOD;
    }
}

int N, A[101010];

int main() {
    init();
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += A[i] * (sum_inv[i+1] + sum_inv[N-i] - 1) % MOD * fact[N] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    
    return 0;
}
