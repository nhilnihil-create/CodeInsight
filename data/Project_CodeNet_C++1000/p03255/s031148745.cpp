#include <cstdio>
#include <iostream>
#define N 200010
using namespace std;
typedef long long i64;
i64 n, X, x[N], sum[N], Ans = 1LL << 62;

int main() {
    cin >> n >> X;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", x + i),
        sum[i] = sum[i - 1] + x[i];
    for (i64 k = 1; k <= n; ++k) {
        i64 res = k * X; 
        for (int j = 0; j <= n / k; ++j) {
            i64 M = n - j * k, m;
            m = max(M - k, 0LL);
            i64 c = j == 0 ? 5 : j * 2 + 3;
            res += (i64) c * (sum[M] - sum[m]);
            if (res < 0) break;
        }
        if (res > 0) Ans = min(Ans, res);
    }
    cout << Ans + n * X;
    return 0;
}
