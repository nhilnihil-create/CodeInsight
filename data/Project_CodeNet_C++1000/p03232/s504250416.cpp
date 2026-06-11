#include <iostream>
#include <vector>
using namespace std;

const int MAX = 210000;
const int MOD = 1000000007;

long long fac[MAX], inv[MAX], sum_inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    sum_inv[0] = 0, sum_inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        sum_inv[i] = sum_inv[i-1] + inv[i] % MOD;
    }
}

int main() {
    COMinit();
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        long long left = (sum_inv[i+1] - 1 + MOD) % MOD;
        long long right = (sum_inv[N-i] - 1 + MOD) % MOD;
        long long count = fac[N] * (left + right + 1) % MOD;
        res = (res + count * A[i] % MOD) % MOD;
    }
    cout << res << endl;
}
