#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

const int MOD = 998244353;
const int MAXN = 3e5 + 7;

int mul(int a, int b) {
    return (a * b) % MOD;
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int fact[MAXN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(i, fact[i - 1]);
    }
}

int C(int n, int k) {
    int up = fact[n];
    int dw = mul(fact[k], fact[n - k]);
    return mul(up, binpow(dw, MOD - 2));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    for (int c1 = 0; c1 <= n; c1++) {
        int c2 = (k - c1 * a) / b;
        if (c2 < 0 || c2 > n || c1 * a + c2 * b != k) continue;
        ans = add(ans, mul(C(n, c1), C(n, c2)));
    }
    cout << ans << endl;
}   
