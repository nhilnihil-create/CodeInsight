#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, ans, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, j; i <= n; i = j) {
        for (j = i; a[i] == a[j]; j++);
        ans += (j - i) >> 1;
    }
    printf("%d\n", ans);
    return 0;
}