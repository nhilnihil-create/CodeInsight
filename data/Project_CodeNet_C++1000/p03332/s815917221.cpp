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
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

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
    std::vector<long long> fac, den;
    Combi_Num() {}
    Combi_Num(const int n, const int mod_num_in) {
        mod_num = mod_num_in;
        fac.resize(n+1, 0);
        den.resize(n+1, 0);
        fac[0] = 1;
        den[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = (fac[i-1] * i) % mod_num;
            den[i] = (den[i-1] * pow_mod(i, mod_num - 2, mod_num)) % mod_num;
        }
    }

    long long calc(const int n, const int r) {
        return (fac[n] * ((den[r] * den[n-r]) % mod_num)) % mod_num;
    }
};

const long long MAX_N = 300050;
const long long MOD = 998244353;
long long N, A, B, K;

Combi_Num combi_num = Combi_Num(MAX_N, MOD);

int main(int argc, char **argv) {
    std::cin >> N >> A >> B >> K;

    long long ret = 0;
    for (long long rnum = 0; rnum <= N; rnum++) {
        if (A * rnum <= K && (K - A * rnum) % B == 0) {
            long long bnum = (K - A * rnum) / B;
            if (bnum <= N) {
                long long tmp = (combi_num.calc(N, rnum) * combi_num.calc(N, bnum)) % MOD;
                ret = (ret + tmp) % MOD;
            }
        }
    }
    
    std::cout << ret << std::endl;
    
    return 0;
}
