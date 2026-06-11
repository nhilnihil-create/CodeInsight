  #include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
#include <numeric>
using namespace std;

#define INF 1e18
#define int long long

const int MAX = 1000100;
const int MOD = 998244353;

int fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

int COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main() {
    COMinit();

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        int j = (k - a * i) / b;
        if(j >= 0 && (k - a * i) % b == 0) {
            ans += COM(n, i) * COM(n, j) % MOD;
        }
    }

    ans %= MOD;
    
    cout << ans << endl;
    return 0;
}
