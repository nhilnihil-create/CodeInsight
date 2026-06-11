#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 10;

int N, rnk[MAX_N], siz[MAX_N], pa[MAX_N], depth[MAX_N];
ll D[MAX_N];
map<ll, int> mp;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%lld", &D[i]), mp[D[i]] = i;
    for (int i = 1; i <= N; i++) rnk[i] = i, siz[i] = 1;
    sort(rnk + 1, rnk + N + 1, [](int a, int b) { return D[a] > D[b]; });
    for (int i = 1; i < N; i++) {
        int x = rnk[i];
        ll pd = D[x] + 2 * siz[x] - N;
        if (siz[x] * 2 < N && mp.count(pd)) {
            pa[x] = mp[pd];
            siz[pa[x]] += siz[x];
        } else {
            printf("-1\n");
            return 0;
        }
    }
    ll sum = 0;
    for (int i = N - 1; i; i--) {
        int x = rnk[i];
        depth[x] = depth[pa[x]] + 1;
        sum += depth[x];
    }
    if (sum != D[rnk[N]]) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i < N; i++) {
        int x = rnk[i];
        printf("%d %d\n", x, pa[x]);
    }
}
