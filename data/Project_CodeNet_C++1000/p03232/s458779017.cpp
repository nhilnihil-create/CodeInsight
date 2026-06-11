#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define N_MAX 100000
long long S[N_MAX + 1];

long long power(long long a, int p) {
    if(p == 1) return a;
    else {
        long long ret = power(a, p / 2);
        ret = ret * ret % mod;
        if(p & 1) ret = ret * a % mod;
        return ret;
    }
}

void init() {
    S[0] = 0;
    for(int i=1; i<=N_MAX; ++i) {
        S[i] = (S[i - 1] + power(i, mod - 2)) % mod;
    }
}

int main() {
    init();
    long long N;
    cin >> N;
    long long res = 0;
    for(int j=1; j<=N; ++j) {
        long long A;
        cin >> A;
        res += A * ((1 + S[j] - S[1] + S[N - j + 1] - S[1]) % mod) % mod;
        res %= mod;
    }

    long long fac = 1;
    for(int i=2; i<=N; ++i) {
        fac *= i;
        fac %= mod;
    }

    cout << (res * fac) % mod << endl;
}