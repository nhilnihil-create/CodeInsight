# include <iostream>
const int MAX = 3e5 + 2;
const long long MOD = 998244353;
using namespace std;

long long fm_table[MAX];
long long ifm_table[MAX];
long long bm_table[MAX];


long long pow_mod (long long x, long long m, long long mod) {
    if (m == 0){
        return 1;
    } else { 
        long long temp = pow_mod(x, m/2, mod);
        if (m % 2 == 0) {
            return temp * temp % mod;
        } else {
            return temp * temp % mod * x % mod;
        }
    }
}
 
long long inv_mod (long long x, long long mod) {
    return pow_mod(x, mod - 2, mod);
}
 
int main() {
    long long N, A, B, K;
    cin >> N >> A >> B >> K;
 
    long long ret = 0;
 
    long long temp = 1;
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            fm_table[0] = 1;
            ifm_table[0] = 1;
        } else {
            temp = temp * i % MOD;
            fm_table[i] = temp;
            ifm_table[i] = inv_mod(temp, MOD);
        }
    }
    for (int i = 0; i * 2 <= N; i++) {
        temp = fm_table[N] * ifm_table[i] % MOD
            * ifm_table[N - i] % MOD;
        bm_table[i] = temp;
        bm_table[N - i] = temp;
    }
 
    for (long long i = 0; i <= N; i++) {
        long long rest = K - i * A;
        if (rest >= 0 && rest <= B * N && rest % B == 0){
            long long j = rest / B;
            ret = (ret + bm_table[i] * bm_table[j] % MOD) % MOD;
        }
    }
    
    cout << ret << endl;
}