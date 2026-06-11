#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;
template<class T> void add(T &a, T b) { (a += (b % MOD + MOD) % MOD) %= MOD; }

long long modpow(long long a, long long n, long long mod = MOD) {
	long long res = 1;
	while (n > 0) { if (n & 1) (res *= a) %= mod; (a *= a) %= mod; n >>= 1; }
	return res;
}

int main() {
    const int inv = 111111112;
    string s; cin >> s;
    int a = 0,
        l = 0,
        c = count(begin(s), end(s), 'C'),
        r = count(begin(s), end(s), '?');
    long long ans = 0;
    auto calc = [&](int a, int l, int c, int r) {
        long long res = modpow(3, l + r) * inv % MOD;
        res = res * (a * 3 + l) % MOD;
        res = res * (c * 3 + r) % MOD;
        return res;
    };
    for (char ch: s) {
        if (ch == 'A') a++;
        if (ch == 'B') add(ans, calc(a, l, c, r));
        if (ch == 'C') c--;
        if (ch == '?') add(ans, calc(a, l++, c, --r));
    }
    cout << ans << endl;
    return 0;
}
