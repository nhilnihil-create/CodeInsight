#include<bits/stdc++.h>
using namespace std;

int main(void) {
    constexpr long MOD = 998244353;

    long n, a, b, k;
    cin >> n >> a >> b >> k;

    auto inv = [&](){
        map<long,long> c;

        return [&, c](long a) mutable {
            long r = 1, b = MOD-2;
            while(b) {
                if(b&1) r *= a, r %= MOD;
                a *= a, a %= MOD;
                b >>= 1;
            }
            return r;
        };
    }();

    auto comb = [&](){
        map<long,long> c;

        return [&, c](long _, long b) mutable {
            if(c.count(b)) return c[b];

            long a = n;
            long r = 1;
            for(long i=0; i<=n; i++)
                c[i] = r, r *= a-i, r %= MOD, r *= inv(i+1), r %= MOD;
            return c[b];
        };
    }();

    long r = 0;
    for(long x=0; x<=n; x++) {
        if((k-x*a)%b) continue;
        long y = (k - x*a)/b;
        if(y < 0) continue;
        if(y > n) continue;

        // ax + by == k
        r += (comb(n, x) * comb(n, y)) % MOD;
        r %= MOD;
    }
    cout << r << endl;
}
