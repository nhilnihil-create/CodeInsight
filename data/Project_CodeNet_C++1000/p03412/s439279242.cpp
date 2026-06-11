#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    int ans = 0;
    for (int i = 0; i <= 28; i++) {
        int P = 1 << (i + 1);
        for (int j = 1; j <= n; j++) {
            c[j] = a[j] % P, d[j] = b[j] % P;
        }
        sort(c + 1, c + n + 1, greater<int>());
        sort(d + 1, d + n + 1);
        auto query = [&](int x) {
            long long ans = 0;
            for (int i = 1, j = 0; i <= n; i++) {
                while (j < n && c[i] + d[j + 1] < x) j++;
                ans += j;
            }
            return ans;
        };
        long long sum = query((1 << i) * 2) - query(1 << i);
        sum += query((1 << i) * 4) - query((1 << i) * 3);
        if (sum & 1) ans ^= (1 << i);
    }
    printf("%d\n", ans);
    return 0;
}