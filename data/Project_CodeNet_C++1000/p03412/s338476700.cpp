# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+30;
LL a[maxn], b[maxn], ans=0;
template <class T>
inline void scan(T &ret)
{
    char c;ret = 0;
    while((c=getchar())<'0' || c>'9');
    while(c>='0' && c<='9') ret=ret*10+(c-'0'), c=getchar();
}
void out(LL ret)
{
    if(ret>=10) out(ret/10);
    putchar(ret%10+'0');
}
int main()
{
    int n, l, r;
    scan(n);
    for(int i=0; i<n; ++i) scan(a[i]);
    for(int i=0; i<n; ++i) scan(b[i]);
    for(int i=28; ~i; --i)
    {
        LL s = 1LL<<i, tmp=0;
        for(int j=0; j<n; ++j) a[j]%=(s<<1), b[j]%=(s<<1);
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
    out(ans);
    putchar('\n');
    return 0;
}
