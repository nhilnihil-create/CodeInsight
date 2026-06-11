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
signed main()
{
    int n,k;
    n=read(), k=read();
    int res=0;
    for(ri int i=k+1;i<=n;i++)
    {
        int pp=i-k;
        res+=pp*(n/i);
        res+=max(n-n/i*i-max(k-1,0ll),0ll);
    }
    printf("%lld\n",res);
    return 0;
}