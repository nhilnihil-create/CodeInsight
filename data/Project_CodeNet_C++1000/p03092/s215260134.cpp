#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

#define N 5003
#define INF 0x3f3f3f3f3f3f3f3f

inline void cmax(long long &x, long long y) { if (x < y) x = y;}
inline void cmin(long long &x, long long y) { if (x > y) x = y;}

int n, A, B, a[N], pos[N];
long long f[N][N << 1], res = INF;

int main() {
    cin >> n >> A >> B;
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), pos[a[i]] = i;
    for (int i = 1; i <= n; ++i) {
        long long tmp = INF;
        for (int j = 0; j <= n << 1; ++j) {
            if (j & 1) {
                int p = (j + 1) >> 1;
                cmin(tmp, f[i - 1][j] + (p == pos[i] ? 0 : (p < pos[i] ? B : A)));
            } else {
                int p = j >> 1;
                cmin(tmp, f[i - 1][j] + (p < pos[i] ? B : A));
            }
            f[i][j] = tmp;
        }
    }
    long long ans = INF;
    for (int j = 0; j <= n << 1; ++j)
        cmin(ans, f[n][j]);
    cout << ans << endl;
    return 0;
}
