#include<bits/stdc++.h>

#define ll long long
#define met(a, x) memset(a,x,sizeof(a))
#define inf 0x3f3f3f3f
#define ull unsigned long long
#define mp make_pair

using namespace std;
const int mod = 998244353;
const int N = 3e5 + 10;
const int M = 1e6 + 10;
ll fac[N], inv[N];

ll ksm(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b % 2)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init() {
    int i;
    fac[0] = 1;
    for (i = 1; i < N; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv[N - 1] = ksm(fac[N - 1], mod - 2);
    for (i = N - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
long long C(ll n,ll m) {
    if (n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    init();
    for (ll i = 0; i <= n; i++) {
        if (a * i > k) {
            break;
        }
        if ((k - a * i) % b) {
            continue;
        }
        ll cnt = (k - a * i) / b;
        if (cnt > n) {
            continue;
        }
        ans = (ans + C(n, i) % mod * C(n, cnt) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}