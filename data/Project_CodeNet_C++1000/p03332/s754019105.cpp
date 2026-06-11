#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAX = 300001;
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
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}
long long N, A, B, K;
int f(int na, int nb)
{
    return COM(N, na) * COM(N, nb) % MOD;
}
int main()
{
    COMinit();
    cin >> N >> A >> B >> K;
    long long ans = 0;
    for (int i = 0; i <= N; i++) {
        if ((K - A * i) % B == 0) {
            int j = (K - A * i) / B;
            if (j <= N) {
                ans += f(i, j);
            }
        }
    }
    cout << ans % MOD << endl;
    return 0;
}
