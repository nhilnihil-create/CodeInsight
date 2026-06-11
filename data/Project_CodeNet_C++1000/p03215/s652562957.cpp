#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
LL sum[maxn];
LL v[maxn * (maxn - 1) / 2];
bool vis[maxn * (maxn - 1) / 2];
bitset<45> p[maxn * (maxn - 1) / 2];
LL num[50];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &sum[i]);
        sum[i] += sum[i - 1];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            v[++cnt] = sum[j] - sum[i];
            LL m = v[cnt], g = 0;
            while (m) {
                if (m & 1){
                    p[cnt].set(g);
                    num[g]++;
                }
                m >>= 1;
                g++;
            }
        }
    }
    for (int j = 44; j >= 0; j--) {
        if(num[j] < k)
            continue;
        for (int i = 1; i <= cnt; i++) {
            if (vis[i])
                continue;
            if (!p[i][j]) {
                vis[i] = true;
                for (int l = 0; l < 45; l++) 
                    if(p[i][l])
                        num[l]--;
            }
        }
    }
    LL ans = (LL(1) << 45) - 1;
    for (int i = 1; i <= cnt; i++) {
        if(vis[i])
            continue;
        ans &= v[i];
        k--;
        if (k == 0)
            break;
    }
    printf("%lld\n", ans);
    return 0;
}