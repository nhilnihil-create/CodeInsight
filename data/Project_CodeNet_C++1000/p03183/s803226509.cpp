#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define MAXN 1005
#define MAXM 10005
#define INF 0x3f3f3f3f
#define rint register int
#define LL long long
#define LD long double
using namespace std;

int n;
LL ans, f[MAXM*2];

struct A {int w, s, v;} a[MAXN];

bool CMP(A x, A y)
{
    return x.w+x.s<y.w+y.s;
}

int main()
{
    scanf("%d", &n);
    for(rint i=1; i<=n; ++i) scanf("%d%d%d", &a[i].w, &a[i].s, &a[i].v);
    sort(a+1, a+n+1, CMP);
    for(rint i=1; i<=n; ++i)
	for(rint j=a[i].s; j>=0; j--) f[j+a[i].w]=max(f[j+a[i].w], f[j]+a[i].v);
    for(rint i=0; i<=20000; ++i) ans=max(ans, f[i]);
    printf("%lld\n", ans);
    return 0;
}
