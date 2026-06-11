#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010, P = 998244353;
int n, fact[maxn], finv[maxn];
ll a, b, s;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int C(int x, int y) {
    return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
}

int main() {
    cin >> n >> a >> b >> s;
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ll r = n * (a + b) - s - i * a;
        if (r < 0 || r % b) continue;
        ll t = r / b;
        if (t > n) continue;
        ans = (ans + 1LL * C(n, i) * C(n, t)) % P;
    }
    cout << ans << endl;
    return 0;
}