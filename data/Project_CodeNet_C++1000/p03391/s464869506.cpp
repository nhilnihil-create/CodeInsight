#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; (i) < (int) (n); (i) ++)
using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<int> a(n), b(n);
        int mi = 1e9 + 5;
        long long s = 0;
        rep(i, n) {
                scanf("%d%d", &a[i], &b[i]);
                if (a[i] > b[i]) {
                        mi = min(mi, b[i]);
                }
                s += a[i];
        }
        if (mi == 1e9 + 5) {
                printf("0\n");
        } else {
                printf("%lld\n", s - mi);
        }
        return 0;
}
