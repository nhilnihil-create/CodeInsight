#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, a[maxn], pre[maxn], f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = f[0] = 1; i <= n; i++) {
        scanf("%d", &a[i]), f[i] = f[i - 1];
        if (pre[a[i]] && pre[a[i]] < i - 1) (f[i] += f[pre[a[i]]]) %= P;
        pre[a[i]] = i;
    }
    printf("%d\n", f[n]);
    return 0;
}