#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>

long long pow_mod(long long x, long long n, long long mod_num) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) { res = (res * x) % mod_num; }
        x = (x * x) % mod_num;
        n = (n >> 1);
    }
    return res;
}

class Combi_Num {
    public:
    long long mod_num;
    std::vector<long long> factorial, factorial_inv, inv;
    Combi_Num() {}
    Combi_Num(const int n, const long long mod_num_in) {
        mod_num = mod_num_in;
        factorial.resize(n+1, 0);
        factorial_inv.resize(n+1, 0);
        inv.resize(n+1, 0);
        factorial[0] = 1;
        factorial_inv[0] = 1;
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % mod_num;
            inv[i] = pow_mod(i, mod_num - 2, mod_num);
            factorial_inv[i] = (factorial_inv[i-1] * inv[i]) % mod_num;
        }
    }

    long long calc(const int n, const int r) {
        return (factorial[n] * ((factorial_inv[r] * factorial_inv[n-r]) % mod_num)) % mod_num;
    }
};

const long long MOD = 1000000007;
const int MAX_N = 100050;
int N;
long long A[MAX_N];

Combi_Num combi_num = Combi_Num(MAX_N, MOD);
long long ac[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    ac[0] = 0;
    for (int i = 1; i <= N; i++) {
        ac[i] = ac[i-1] + (combi_num.factorial[N] * combi_num.inv[i]) % MOD;
        ac[i] = ac[i] % MOD;
    }

    long long ret = 0;
    for (int i = 1; i <= N; i++) {
        long long tmp = 0;
        tmp = (tmp + ac[i]) % MOD;
        tmp = (tmp + ac[N-i+1]) % MOD;
        tmp = (tmp - ac[1] + MOD) % MOD;
        ret = ret + (tmp * A[i]) % MOD;
        ret = ret % MOD;
    }

    std::cout << ret << std::endl;
    
    return 0;
}