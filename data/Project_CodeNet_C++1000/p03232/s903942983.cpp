#include<bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
using namespace std;

int n, a[maxn], b[maxn], vis[20];
int fac[maxn], A[maxn], sum[maxn];

int main() {
    ios::sync_with_stdio(0);
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = (ll)fac[i - 1] * i % mod;
    cin >> n;
    A[0] = 1;
    for(int i = 1; i <= n; i++) A[i] = (ll)A[i - 1] * (n - i + 1) % mod;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        int v = (ll)fac[i] * A[n - (i + 1)] % mod;
        sum[i] = (sum[i - 1] + v) % mod;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += (ll)a[i] * fac[n] % mod;
        ans += (ll)a[i] * sum[i - 1] % mod;
        ans += (ll)a[i] * sum[n - i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}