#include <bits/stdc++.h>
using namespace std;

int n, K, q, a[2010];

int main() {
    scanf("%d %d %d", &n, &K, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        auto chk = [&](int x) {
            vector<int> V;
            for (int l = 1, r = 1; l <= n; l = r) {
                vector<int> num;
                while (l <= n && a[l] < x) l++;
                r = l;
                while (r <= n && a[r] >= x) r++;
                for (int i = l; i <= min(r - 1, n); i++) num.push_back(a[i]);
                if (num.size() >= K) {
                    sort(num.begin(), num.end());
                    for (int i = 0; i <= num.size() - K; i++) V.push_back(num[i]);
                }
            }
            sort(V.begin(), V.end());
            if (V.size() >= q) ans = min(ans, V[q - 1] - V[0]);
        };
        chk(a[i]);
    }
    printf("%d\n", ans);
    return 0;
}