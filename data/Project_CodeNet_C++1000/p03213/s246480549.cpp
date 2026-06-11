#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t % mod;
    } else {
        return modpow(m, n - 1) * m % mod;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

long long nCkmod(long long n, long long k) {
    long long denomi = 1;
    REP(i, n) {
        denomi *= (i + 1);
        denomi %= mod;
    }
    long long numera = 1;
    for (int i = n - k; i > 0; i--) {
        numera *= i;
        numera %= mod;
    }
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}

void print_binary(long long a) {
    for (int i = 31; i >= 0; i--) {
        cout << (a >> i & 1);
    }
    cout << endl;
}

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
array<int, 101> factoring(int x) {
    array<int, 101> ret{};
    for (int i = 2; x >= i * i; i++) {
        while (x % i == 0) {
            ret[i]++;
            x /= i;
        }
    }
    if (x > 1) ret[x]++;
    return ret;
}
signed main() {
    int n;
    cin >> n;
    array<int, 101> fac{};
    for (int i = 1; i < n + 1; i++) {
        array<int, 101> save;
        save = factoring(i);
        for (int j = 0; j < n + 1; j++) {
            fac[j] += save[j];
        }
    }
    int cnt2, cnt4, cnt14, cnt74;
    int ans = 0;
    for (int i = 2; i < 101; i++) {
        for (int j = i; j < 101; j++) {
            for (int k = 2; k < 101; k++) {
                if (fac[k] >= 2 && fac[j] >= 4 && fac[i] >= 4 && i != k && k != j && j != i) {
                    ans++;
                }
            }
        }
    }
    for (int j = 2; j < 101; j++) {
        for (int k = 2; k < 101; k++) {
            if (fac[k] >= 4 && fac[j] >= 14 && k != j) {
                ans++;
            }
        }
    }
    for (int j = 2; j < 101; j++) {
        for (int k = 2; k < 101; k++) {
            if (fac[k] >= 2 && fac[j] >= 24 && k != j) {
                ans++;
            }
        }
    }
    for (int k = 2; k < 101; k++) {
        if (fac[k] >= 74) {
            ans++;
        }
    }
    cout << ans << endl;
}