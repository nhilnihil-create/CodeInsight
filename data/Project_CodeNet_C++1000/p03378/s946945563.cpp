#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m,k,p,q;
signed main()
{
    n=read(), m=read(), k=read();
    for(ri int i=1;i<=m;i++)
    {
        int x=read();
        if(x<k) p++;
        if(x>k) q++;
    }
    printf("%lld\n",min(p,q));
    return 0;
}