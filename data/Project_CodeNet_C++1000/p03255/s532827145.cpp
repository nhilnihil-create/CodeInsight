#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL maxn=2e5+5;
LL n, x, a[maxn], A[maxn];
LL val(LL x){ return x==1?5:2*x+1; }

int main(){
    scanf("%lld%lld", &n, &x); LL ans=0x3f3f3f3f3f3f3f3f;
    for (LL i=1; i<=n; ++i) scanf("%lld", &a[i]), A[i]=A[i-1]+a[i];
    for (LL k=1; k<=n; ++k){  //取k次
        LL cans=k*x, cnt=1;
        for (LL i=n; i>0; i-=k, ++cnt){
            cans+=(A[i]-A[max(i-k, 0ll)])*val(cnt);
            if (cans>ans) break;
        }
        ans=min(ans, cans);
    }
    printf("%lld\n", ans+n*x);
    return 0;
}
