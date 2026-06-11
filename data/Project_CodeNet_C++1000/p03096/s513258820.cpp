#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 1000000007

int f[200005];
int val[200005];
int a[200005];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i-1]) {
            f[i] = f[i-1]; continue;
        }
        val[a[i]] += f[i-1];
        if (val[a[i]] >= MOD) val[a[i]] -= MOD;
        f[i] = val[a[i]];
    }
    printf("%d", f[n]);
    return 0;
}
