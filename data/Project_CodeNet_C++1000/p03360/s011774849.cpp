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
signed main()
{
    int a,b,c;
    a=read(), b=read(), c=read();
    int tt=a+b+c;
    int qwq=max(max(a,b),c);
    int ty=qwq;
    int res=1;
    int K=read();
    for(ri int i=1;i<=K;i++) res*=2ll;
    qwq*=res;
    printf("%lld\n",tt+qwq-ty);
    return 0;
}