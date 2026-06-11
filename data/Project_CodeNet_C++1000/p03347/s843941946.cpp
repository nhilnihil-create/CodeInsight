#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;



void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    if (a[0] != 0) {
        printf("-1\n"); return;
    }
    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            printf("-1\n"); return;
        }
    }
    ll sum = 0;
    int curr = -INF;
    for (i = n - 1; i > 0; i--) {
        a[i] = MAX(a[i], curr);
        if (a[i] > curr) {
            if (-a[i] > i) {
                printf("-1\n"); return;
            }
            sum += (i - (-a[i]));
            curr = a[i];
        }
    }
    printf("%lld\n", sum);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
