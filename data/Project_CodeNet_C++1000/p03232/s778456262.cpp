#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;
lint minv(lint n) {
    lint res = 1, p = MOD - 2;
    while (p > 0) {
        if (p % 2 == 1) {
            res = res * n % MOD;
        }
        n = n * n % MOD;
        p /= 2;
    }
    return res;
}
lint madd(lint a, lint b) {
    return (a + b) % MOD;
}
lint msub(lint a, lint b) {
    lint res = a - b;
    if (res < 0) {
        res += MOD;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<lint> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    // 1 / n の累積和
    vector<lint> c(N + 1);
    for (int i = 1; i <= N; i++) {
        c[i] = madd(c[i - 1], minv(i));
    }

    lint ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += a[i] * madd(msub(c[i], c[0]), msub(c[N - i + 1], c[1])) % MOD;
    }
    for (int i = 1; i <= N; i++) {
        ans = ans * i % MOD;
    }
    cout << ans << endl;
    return 0;
}