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
int h,w;
int f[210][210];
signed main()
{
    h=read(), w=read();
    for(ri int i=0;i<10;i++)
    for(ri int j=0;j<10;j++)
    f[i][j]=read();

    for(ri int k=0;k<10;k++)
    for(ri int i=0;i<10;i++)
    for(ri int j=0;j<10;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

    int res=0;
    for(ri int i=0;i<h;i++)
    for(ri int j=0;j<w;j++)
    {
        int x=read();
        if(x>=0) res+=f[x][1];
    }
    printf("%lld\n",res);
    return 0;
}