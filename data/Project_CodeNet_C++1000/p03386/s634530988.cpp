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
int a,b,k;
int ot[N],cnt;
map<int,int> Q;
signed main()
{
    a=read(), b=read(), k=read();
    for(ri int i=0;i<k &&i+a<=b;i++)
    {
        if(!Q[i+a]) Q[i+a]=1, ot[++cnt]=i+a;
    }
    for(ri int i=0;i<k&&b-i>=a;i++)
    {
        if(!Q[b-i]) Q[b-i]=1, ot[++cnt]=b-i;
    }
    sort(ot+1,ot+1+cnt);
    for(ri int i=1;i<=cnt;i++) printf("%lld\n",ot[i]);
    return 0;
}