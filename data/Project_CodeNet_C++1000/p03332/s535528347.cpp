#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

const int mod = 998244353;

vector<long long int> fac;

long long int mypow(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long int res = mypow(a, b / 2);
    res = res * res % mod;
    if (b % 2 == 1) res = res * a % mod;
    return res;
}

long long int myc(long long int a, long long int b) {
    return fac[a] * mypow(fac[b], mod - 2) % mod * mypow(fac[a - b], mod - 2) % mod;
}

int main() {
    long long int n, a, b, k;
    cin >> n >> a >> b >> k;
    long long int res = 0;
    fac.push_back(1);
    for (int i = 1; i <= n; i++) {
        fac.push_back(fac.back() * i % mod);
    }
    for (int i = 0; i * a <= k && i <= n; i++) {
        if ((k - i * a) % b != 0 || (k - i * a) / b > n) continue;
        long long int l1 = i, l2 = (k - i * a) / b;
        res += myc(n, l1) * myc(n, l2) % mod;
        res %= mod;
    }
    cout << res << endl;
}


