#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 300001;

long long fc[MAX];
long long fci[MAX];

long long modpow(long long a, long long b) {
    long long bp[31];
    bp[0] = a;
    for (int i=1; i<31; ++i) {
        bp[i] = bp[i-1] * bp[i-1] % MOD;
    }
    long long ret = 1;
    for (int i=0; i<31; ++i) {
        if (b & (1LL << i)) {
            ret *= bp[i];
            ret %= MOD;
        }
    }
    return ret;
}

void init() {
    fc[0] = fc[1] = 1;
    for (int i=2; i<MAX; ++i) {
        fc[i] = (fc[i-1] * i) % MOD;
    }

    fci[1] = 1;
    for (int i=2; i<MAX; ++i) {
        fci[i] = (fci[i-1] * modpow(i, MOD-2)) % MOD;
    }
}

long long C(long long n, long long k) {
    if (k == 0 || n == k) return 1;
    return (fc[n] * fci[k] % MOD) * fci[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int N;
    long long A, B, K;
    cin >> N >> A >> B >> K;

    long long ans = 0;
    for (long long a=0; a*A<=K; ++a) {
        if ( (K-a*A) % B != 0 ) continue;
        long long b = (K-a*A) / B;
        if (N < a || N < b) continue;
        ans += C(N, a) * C(N, b);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}