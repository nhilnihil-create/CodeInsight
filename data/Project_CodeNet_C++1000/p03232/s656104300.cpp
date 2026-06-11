#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (ll i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

const ll MOD = 1000000007LL;

long long inv_mod(long long n, long long mod) {
    long long a = n % mod, b = mod - 2, ret = 1;
    while (b > 0) {
        if (b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

int main () {

    ll N; cin >> N;
    vector < ll > A(N);
    REP(i,N) cin >> A[i];

    ll ans = 1LL;
    REP(i,N) {
        ans *= (ll)(1LL + i);
        ans %= MOD;
    }

    ll sum_t = 0;
    REP(i,N) {
        sum_t += inv_mod(1LL + i, MOD);
        sum_t %= MOD;
    }

    ll sum = 0;
    REP(i,N) {
        sum += sum_t * A[i];
        sum %= MOD;
        sum_t -= inv_mod(N - i, MOD);
        sum_t += inv_mod(i + 2LL, MOD);
        sum_t += MOD;
        sum_t %= MOD;
    }

    cout << (ans * sum) % MOD << endl;

    return 0;
}
