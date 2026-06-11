#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+20;
int n,a[N],b[N],Max,ans;
long long c[N*2];
inline int lowbit(int x) { return x & (-x); }
inline void insert(int p,long long v) { p += n+1; for (;p<=2*n+1;p+=lowbit(p)) c[p] += v; }
inline long long query(int p) { p += n+1; long long res = 0; for (;p;p-=lowbit(p)) res += c[p]; return res; }
inline void input(void)
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]) , Max = max( Max , a[i] );
}
inline long long check(int val)
{
    long long res = 0;
    for (int i=1;i<=n;i++)
        b[i] = a[i] <= val ? 1 : -1;
    for (int i=1;i<=n;i++)
        b[i] += b[i-1];
    memset( c , 0 , sizeof c );
    for (int i=0;i<=n;i++)
    {
        res += query( b[i] - 1 );
        insert( b[i] , 1 );
    }
    return res;
}
inline void BinarySearch(void)
{
    int l = 0 , r = Max , mid;
    while ( l + 1 < r )
    {
        mid = l + r >> 1;
        if ( check(mid) >= 1LL*n*(n+1)/2/2 + 1 ) r = mid;
        else l = mid;
    }
    check(l) == 1LL*n*(n+1)/2/2 + 1 ? ans = l : ans = r;
}
int main(void)
{
    input();
    BinarySearch();
    printf("%d\n",ans);
    return 0;
}
