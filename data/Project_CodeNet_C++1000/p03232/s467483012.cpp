# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
     
const int maxn(1e5 + 5);
const int mod(1e9 + 7);

inline void Inc(int &x, int y) {
    x = x + y >= mod ? x + y - mod : x + y;
}

inline void Dec(int &x, int y) {
    x = x - y < 0 ? x - y + mod : x - y;
}

inline int Add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
     
int n, w[maxn], ans, inv[maxn];

int main() {
    int i;
    scanf("%d", &n), inv[1] = 1;
    for (i = 2; i <= n; ++i) inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
    for (i = 2; i <= n; ++i) Inc(inv[i], inv[i - 1]);
    for (i = 1; i <= n; ++i) scanf("%d", &w[i]), Dec(ans, w[i]);
    for (i = 1; i <= n; ++i) Inc(ans, (ll)w[i] * Add(inv[i], inv[n - i + 1]) % mod);
	for (i = 1; i <= n; ++i) ans = (ll)ans * i % mod;
    printf("%d\n", ans);
    return 0;
}