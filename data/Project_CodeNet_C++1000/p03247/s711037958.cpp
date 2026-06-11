#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1010
using namespace std;

int n, m;
long long x[N], y[N], p[50];

int main() {
#ifdef isLOCAL
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n, m = 35;

    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", x + i, y + i);
        if (i > 1 && ((x[i] + y[i] + x[i - 1] + y[i - 1]) & 1))
            return puts("-1"), 0;
    }

    for (int i = 0; i < m; ++i)
        p[i] = (1ll << i);
    reverse(p, p + m);
    if ((x[1] + y[1]) % 2 == 0) p[m++] = 1;

    cout << m << endl;
    for (int i = 0; i < m; ++i)
        cout << p[i] << " "; cout << endl;

    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < m; ++i)
        if (abs(x[k]) > abs(y[k]))
            x[k] += (x[k] < 0 ? (putchar('L'), 1) : (putchar('R'), -1)) * p[i];
        else y[k] += (y[k] < 0 ? (putchar('D'), 1) : (putchar('U'), -1)) * p[i];
        puts("");
    }

    return 0;
}
