#include <bits/stdc++.h>
using namespace std;

int n, a[100005];

double iabs(double x) {return x > 0 ? x : -x;}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    double T = a[n] / 2.0;
    int t = 1;
    for (int i = 1; i <= n; i++) {
        if (iabs(a[i] - T) < iabs(a[t] - T)) t = i;
    }
    printf("%d %d\n", a[n], a[t]);
    return 0;
}
