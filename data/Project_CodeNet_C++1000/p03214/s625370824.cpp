#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    double ave = sum * 1.0 / n;
    int g = 0;
    double m = 200;
    for (int i = 1; i <= n; i++) {
        if(abs(a[i] - ave) < m) {
            m = abs(a[i] - ave);
            g = i;
        }
    }
    printf("%d\n", g - 1);
    return 0;
}