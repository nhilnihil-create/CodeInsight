#include "bits/stdc++.h"

using namespace std;

using ll = long long;

template<typename T> using V = std::vector<T>;
using Vi = V<int>;
using VVi = V<V<int>>;
using Vl = V<ll>;
using VVl = V<V<ll>>;
using Vs = V<string>;

template<typename T1, typename T2> using P = std::pair<T1, T2>;
using Pii = P<int, int>;
using Pll = P<ll, ll>;
using Pdd = P<double, double>;

template<typename T1, typename T2> using M = std::map<T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

const double PI = acos(-1);
const ll MOD = 1e9+7;

int n;
Vi primes;

std::map<int, int> prime_fact(long long n) {
    std::map<int, int> cnt;

    long long m = n;
    for (int i: primes) {
        if (m % i == 0) {
            cnt[i] = 1;
            m /= i;
        }
        while (m % i == 0) {
            cnt[i]++;
            m /= i;
        }
    }
    if (m != 1) {
        cnt[m] = 1;
    }

    return cnt;
}

int main() {
    cin >> n;

    primes = Vi();
    V<bool> isPrime(n+1, true);
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        long long buf = i * 2;
        while (buf <= n) {
            isPrime[buf] = false;
            buf += i;
        }
    }

    Mii m;
    REP2(i, 2, n+1) {
        Mii m2 = prime_fact(i);
        for (auto x: m2) {
            if (m.count(x.first) == 0) {
                m[x.first] = x.second;
            } else {
                m[x.first] += x.second;
            }
        }
    }

    int c75 = 0, c25 = 0, c15 = 0, c5 = 0, c3 = 0;
    for (auto x: m) {
        if (x.second >= 74) c75++;
        else if (x.second >= 24) c25++;
        else if (x.second >= 14) c15++;
        else if (x.second >= 4) c5++;
        else if (x.second >= 2) c3++;
    }

    int res = c75;
    c25 += c75;
    res += c25 * (c25 - 1) + c25 * (c3 + c5 + c15);
    c15 += c25;
    res += c15 * (c15 - 1) + c15 * c5;
    c5 += c15;
    res += c5 * (c5-1) * (c5-2) / 2 + c5 * (c5-1) / 2 * c3;
    cout << res << '\n';

    return 0;
}
