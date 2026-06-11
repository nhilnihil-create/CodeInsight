#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = 1e9 + 7, INF = 1e9;


int main(void) {
    int r, g, b, n, i, j, re, ans;

    scanf("%d%d%d%d", &r, &g, &b, &n);

    ans = 0;
    for (i = 0; r * i <= n; i++) {
        for (j = 0; r * i + g * j <= n; j++) {
            re = n - r * i - g * j;
            if (re >= 0 && re % b == 0) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}