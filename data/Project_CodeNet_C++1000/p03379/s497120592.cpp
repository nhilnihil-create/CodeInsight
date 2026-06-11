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
int n;
struct Node
{
    int w,id;
}a[N];
int ot[N];
inline bool cp(Node x,Node y) { return x.w<y.w; }
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i].w=read(), a[i].id=i;
    sort(a+1,a+1+n,cp);
    for(ri int i=1;i<=n/2;i++) ot[a[i].id]=a[n/2+1].w;
    for(ri int i=n/2+1;i<=n;i++) ot[a[i].id]=a[n/2].w;
    for(ri int i=1;i<=n;i++) printf("%lld\n",ot[i]);
    return 0;
}