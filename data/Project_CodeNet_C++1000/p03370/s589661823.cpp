#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=500010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,X,res,ans;
int a[N];
signed main()
{
    n=read(), X=read();
    for(ri int i=1;i<=n;i++) a[i]=read(), res+=a[i];
    sort(a+1,a+1+n);
    while(res+a[1]<=X) res+=a[1], ans++;
    printf("%lld\n",ans+n);
    return 0;
}