#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }   
    return ans;
}   
void add(int &a, int b) {
    a = mod(a + b);
}   
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
const int N = 1e6 + 7;
int f[N];
int C(int n, int k) {
    return mdiv(f[n], mod(f[k] * f[n - k]));
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mod(f[i - 1] * i);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    for (int i = 0; i <= n && i * a <= k; ++i) {
        int t = k - i * a;
        if (t % b == 0 && t/b <= n) {
            add(ans, C(n, i) * C(n, t / b));
        }   
    }   
    cout << ans << '\n';
}   