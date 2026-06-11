#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

signed main() {
    long long a, b, ans = 0;
    cin >> a >> b;
    if (a % 2 == 1) {
        ans += a;
        a += 1;
    }
    if ((((b - a) + 1) / 2) % 2 == 1) {
        ans = ans ^ 1;
    }
    if ((b - a) % 2 == 0) {
        ans ^= b;
    }
    cout << ans << endl;
}