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
int n,C,s[N],t[N],c[N],qz[N],f[N];
signed main()
{
    n=read(), C=read();
    for(ri int i=1;i<=n;i++) s[i]=read(), t[i]=read(), c[i]=read();
    for(ri int i=1;i<=C;i++)
    {
        memset(qz,0,sizeof(qz));
        for(ri int j=1;j<=n;j++) if(i==c[j]) qz[s[j]]++, qz[t[j]+1]--;
        for(ri int j=1;j<=100000;j++) qz[j]+=qz[j-1];
        for(ri int j=1;j<=100000;j++) if(qz[j]>0) f[j]++;
    }
    int res=0;
    for(ri int i=1;i<=100000;i++) res=max(res,f[i]);
    printf("%lld\n",res);
    return 0;
}