#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, z, w, i, a[2003], ans;

    scanf("%d%d%d", &n, &z, &w);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 1) {
        printf("%d\n", abs(a[0] - w));
        return 0;
    }

    ans = max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1]));

    printf("%d\n", ans);

    return 0;
}