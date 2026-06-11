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
int n,f[N][17],g[N][17],t[210], res=-1e18;
signed main()
{
    n=read();
    for(ri int i=0;i<n;i++)
    for(ri int j=0;j<10;j++)
    f[i][j]=read();

    for(ri int i=0;i<n;i++)
    for(ri int j=0;j<=10;j++)
    g[i][j]=read();

    for(ri int i=1;i<(1ll<<10);i++)
    {
        memset(t,0,sizeof(t));
        for(ri int j=0;j<n;j++)
        for(ri int k=0;k<10;k++)
        if(f[j][k] && ((i>>k)&1ll)) t[j]++;
        
        int qwq=0;
        for(ri int j=0;j<n;j++) qwq+=g[j][t[j]];

        res=max(res,qwq);
    }
    printf("%lld\n",res);
    return 0;
}