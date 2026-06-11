#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MD = 998244353;
const int MN = 333333;
int a, b, n;
ll k;
int c[MN], inv[MN];

void first() {
    inv[1] = 1;
    for (int i = 2; i < MN; i++) {
        inv[i] = ll(inv[MD % i]) * (MD - MD / i) % MD;
    }
    c[0] = 1;
    for (int i = 0; i < n; i++) {
        c[i + 1] = ll(c[i]) * inv[i + 1] % MD * (n - i) % MD;
    }
}

int main() {
    cin >> n >> a >> b >> k;
    first();
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ll rm = k - ll(i) * a;
        if (rm < 0 || rm % b || rm / b > n) continue;
        ans += ll(c[i]) * c[rm / b] % MD;
        if (ans >= MD) ans -= MD;
    }
    cout << ans << endl;
    return 0;
}