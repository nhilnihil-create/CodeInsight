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
int n,a[N],res;
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read(), res+=abs(a[i]-a[i-1]);
    res+=abs(a[n]);
    for(ri int i=1;i<=n;i++) printf("%lld\n",res+abs(a[i-1]-a[i+1])-abs(a[i-1]-a[i])-abs(a[i]-a[i+1]));
    return 0;
}