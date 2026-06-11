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
int D,h,w,x[N],y[N],qz[N];
signed main()
{
    h=read(), w=read(), D=read();
    for(ri int i=1;i<=h;i++)
    {
        for(ri int j=1;j<=w;j++)
        {
            int k=read();
            x[k]=i, y[k]=j;
        }
    }
    for(ri int i=D+1;i<=h*w;i++) qz[i]=qz[i-D]+abs(x[i]-x[i-D])+abs(y[i]-y[i-D]);
    for(ri int Q=read();Q;Q--)
    {
        int p,q;
        p=read(), q=read();
        printf("%lld\n",qz[q]-qz[p]);
    }
    return 0;
}