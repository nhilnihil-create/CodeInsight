#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,Z,W,a[N];
signed main()
{
    n=read(), Z=read(), W=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    if(n>1) printf("%lld\n",max(abs(a[n]-W),abs(a[n]-a[n-1])));
    else printf("%lld\n",abs(a[n]-W));
    return 0;
}