#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#define int long long

using namespace std;

int n, S[100010], W[100010], D[100010], Sz[100010], F[100010], ans = 0;

int find(int x) {
    int t = lower_bound(D + 1, D + n + 1, x) - D;
    if(D[t] != x) {
        puts("-1");
        exit(0);
    }
    return t;
}

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &D[i]);
    memcpy(S, D, sizeof D);
    sort(D + 1, D + n + 1);
    for(int i = 1; i <= n; i++) W[find(S[i])] = i;
    for(int i = 1; i <= n; i++) Sz[i] = 1;
    for(int i = n; i > 1; i--) {
        F[i] = find(D[i] - n + Sz[i] * 2);
        Sz[F[i]] += Sz[i];
        ans += Sz[i];
    }
    if(ans != D[1]) {
        puts("-1");
        return 0;
    }
    for(int i = 2; i <= n; i++) printf("%lld %lld\n", W[i], W[F[i]]);
    return 0;
}