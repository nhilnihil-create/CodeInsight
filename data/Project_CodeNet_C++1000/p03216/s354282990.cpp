#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
char s[N];
int n, q;
ll D[N], M[N], DM[N];
int main() {
    scanf("%d%s", &n, s+1);
    for (int i = 1; i <= n; i++) {
        D[i] = D[i-1], M[i] = M[i-1];
        DM[i] = DM[i-1];
        if (s[i] == 'D') D[i]++;
        if (s[i] == 'M') M[i]++, DM[i] += D[i];
    }
    scanf("%d", &q);
    while (q--) {
        int k; scanf("%d", &k);
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'C') {
                int j = max(0, i-k);
                ans += DM[i]-DM[j]-D[j]*(M[i]-M[j]);
            }
        }
        printf("%lld\n", ans);
    }
}
