#include <cstdio>

using namespace std;
using ll = long long;

constexpr int MAX_N = 100100;
constexpr int MOD = 1000000007;

int n;
int arr[MAX_N];

ll fact[MAX_N];
ll sum_inv[MAX_N];

int mod_pow(int b, int e) {
    if (e == 0) return 1;
    ll x = mod_pow(b, e >> 1);
    x = (x * x) % MOD;
    if (e & 1) x = (x * b) % MOD;
    return (int) x;
}

int mod_inv(int x) {
    return mod_pow(x, MOD - 2);
}

int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &arr[i]);
    }

    fact[0] = 1LL;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    sum_inv[0] = 0LL;
    for (int i = 1; i <= n; ++i) {
        sum_inv[i] = (sum_inv[i - 1] + mod_inv(i)) % MOD;
    }

    ll ans = 0LL;
    for (int i = 1; i <= n; ++i) {
        ll prob = 1LL;
        prob = (prob + sum_inv[i] - sum_inv[1] + MOD) % MOD;
        prob = (prob + sum_inv[n - i + 1] - sum_inv[1] + MOD) % MOD;
        ans = (ans + prob * arr[i]) % MOD;
    }

    ans = (ans * fact[n]) % MOD;

    printf("%lld\n", ans);

    return 0;
}
