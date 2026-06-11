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

LL cakes[1005][3];
LL sums[1005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &cakes[i][0], &cakes[i][1], &cakes[i][2]);
    }
    LL choices[8][3] = {
        {1,1,1},
        {-1,1,1},
        {1,-1,1},
        {1,1,-1},
        {-1,-1,1},
        {-1,1,-1},
        {1,-1,-1},
        {-1,-1,-1},
    };
    LL ans = 0;
    for (int c = 0; c < 8; c++) {
        for (int i = 0; i < n; i++) {
            sums[i] = cakes[i][0] * choices[c][0] + cakes[i][1] * choices[c][1] + cakes[i][2] * choices[c][2];
        }
        LL tmp = 0;
        sort(sums, sums + n, [](LL a, LL b){return a > b;});
        for (int i = 0; i < m; i++) {
            tmp += sums[i];
        }
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
}
