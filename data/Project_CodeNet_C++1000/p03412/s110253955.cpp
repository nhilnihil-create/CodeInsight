# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+30;
LL a[maxn], b[maxn], ans=0;
int main()
{
    int n, l, r;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) scanf("%lld",&a[i]);
    for(int i=0; i<n; ++i) scanf("%lld",&b[i]);
    for(int i=28; ~i; --i)
    {
        LL s = 1LL<<i, tmp=0;
        for(int j=0; j<n; ++j) a[j]&=(s<<1)-1, b[j]&=(s<<1)-1;
        sort(b,b+n);
        for(int j=0; j<n; ++j)
        {
            l = lower_bound(b,b+n,s-a[j])-b;
            r = lower_bound(b,b+n,(s<<1)-a[j])-b;
            tmp += r-l;
            l = lower_bound(b,b+n,(s<<1|s)-a[j])-b;
            r = lower_bound(b,b+n, (s<<2)-a[j])-b;
            tmp += r-l;
        }
        if(tmp&1) ans |= s;
    }
    printf("%lld\n",ans);
    return 0;
}
