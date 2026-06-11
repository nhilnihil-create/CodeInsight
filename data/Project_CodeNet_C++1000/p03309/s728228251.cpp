#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
using namespace std;

// 插入此處
LL a[200005];
LL u[200005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        u[i] = a[i] - i;
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%lld ", u[i]);
    // }
    sort(u + 1, u + n + 1);
    LL b = u[n/2 + 1];
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(u[i] - b);
    }
    printf("%lld\n", ans);
}
