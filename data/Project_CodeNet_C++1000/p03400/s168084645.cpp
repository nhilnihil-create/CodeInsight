#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,D,X,a[N];
signed main()
{
    n=read(), D=read(), X=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    int res=X;
    for(ri int i=1;i<=n;i++) res+=(D-1)/a[i]+1;
    printf("%lld\n",res);
    return 0;
}