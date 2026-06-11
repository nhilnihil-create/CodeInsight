#include <iostream>
#include <limits>
#include <cfenv>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
#include <random>
#include <math.h>
#include <list>
#include <random>
#include <functional>


#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))
#define ALL(TheArray) TheArray.begin(), TheArray.end()

using lli = long long int;
using pii = std::pair<int, int>;

template <class T> inline bool chmax(T& a, T b){
    if(a < b){a = b; return true;}
    return false;
}
template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


template <int N, int mod>
struct Init{
    long long int Power[N+1], powInverse[N+1], powInvS[N + 1], Inverse[N + 1];
    constexpr Init():Power(), powInverse(), powInvS(), Inverse(){
        Power[0] = 1; powInverse[0] = 1, powInvS[0] = 0; Inverse[0] = 1;
        for(int x = 1; x <= N; ++x) Power[x] = (Power[x-1] * x) % mod;
        powInverse[N] = inverse(Power[N]);
        for(int x = N; x > 0; --x){
            Inverse[x] = powInverse[x] * Power[x-1] % mod;
            powInverse[x-1] = (powInverse[x] * x) % mod;
        }
        for(int x = 1; x <= N; ++x){
                powInvS[x] = powInvS[x-1] + Inverse[x];
                if(powInvS[x] >= mod) powInvS[x] -= mod;
        }
    }
    constexpr void swap(lli &a, lli &b) const {
        a ^= b; b ^= a; a ^= b;
    }
    constexpr long long int inverse(long long int a) const noexcept{
        long long int b = mod, u = 1, v = 0;
        while (b != 0) { 
            long long int t = a / b; a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= mod; if (u < 0) u += mod;
        return u;
    }
    inline long long int query(int q1, int q2) const noexcept{
        return powInvS[q1] + powInvS[q2];
    }
};

constexpr int N = 1e5;
constexpr int mod = 1e9 + 7;
constexpr Init<N, mod> Q;

int main(void){
    int n; scanf("%d", &n);
    lli res = 0;
    REP(i, n){
        int a; scanf("%d", &a);
        lli val = Q.query(i + 1, n - i) - 1; if(val < 0) val += mod;
        (res += val * a) %= mod;
    }
    (res *= Q.Power[n]) %= mod;
    printf("%lld\n", res);
    return 0;
}