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
signed main()
{
    int a,b,c,x;
    a=read(), b=read(), c=read();
    x=read();
    int res=0;
    for(ri int i=0;i<=a;i++)
    for(ri int j=0;j<=b;j++)
    for(ri int k=0;k<=c;k++)
    if(i*500+j*100+k*50==x) res++;
    printf("%lld\n",res);
    return 0;
}