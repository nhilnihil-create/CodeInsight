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
int n,a[3][N],qz[3][N];
signed main()
{
    n=read();
    for(ri int i=1;i<=2;i++)
    for(ri int j=1;j<=n;j++)
    a[i][j]=read(), qz[i][j]=qz[i][j-1]+a[i][j];

    int res=0;
    for(ri int i=1;i<=n;i++) res=max(res,qz[1][i]+qz[2][n]-qz[2][i-1]);
    printf("%lld\n",res);
    return 0;
}