#include <iostream>
#include <algorithm>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int n, a[20][20];
ll memo[70000] = {};

ll dp(int s) {
    int i, j, t;
    ll res = 0;

    if (s == 0) return 0;
    if (memo[s] >= 0) {
        return memo[s];
    }

    for (i = 0; i < n; i++) for (j = i + 1; j < n; j++) {
        if ((s >> i) % 2 == 1 && (s >> j) % 2 == 1) {
            res += a[i][j];
        }
    }

    for (t = (s - 1) & s; t > 0; t = (t - 1) & s) {
        res = max(res, dp(t) + dp(s - t));
    }
    
    return memo[s] = res;
}

int main(void) {
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
    }

    for (i = 0; i < (1 << n); i++) {
        memo[i] = -1;
    }

    printf("%lld\n", dp((1 << n) - 1));

    return 0;
}