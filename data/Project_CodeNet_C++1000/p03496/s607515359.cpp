#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=500010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],op,oq;
signed main()
{
    n=read(); op=oq=1;
    for(ri int i=1;i<=n;i++)
    {
        a[i]=read();
        if(a[i]<0) op=0;
        if(a[i]>0) oq=0;
    }
    if(op)
    {
        printf("%lld\n",n-1);
        for(ri int i=1;i<n;i++) printf("%lld %lld\n",i,i+1);
    }
    else if(oq)
    {
        printf("%lld\n",n-1);
        for(ri int i=n;i>1;i--) printf("%lld %lld\n",i,i-1);
    }
    else if(!op && !oq)
    {
        int P,Q; P=Q=0;
        int pcp=0,pcq=0;
        for(ri int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(a[i]>P) P=a[i], pcp=i;
            }
            if(a[i]<0)
            {
                if(-a[i]>Q) Q=-a[i], pcq=i;
            }
        }
        printf("%lld\n",n*2-1);
        if(P>=Q)
        {
            for(ri int i=1;i<=n;i++) printf("%lld %lld\n",pcp,i);
            for(ri int i=1;i<n;i++) printf("%lld %lld\n",i,i+1);
        }
        else
        {
            for(ri int i=1;i<=n;i++) printf("%lld %lld\n",pcq,i);
            for(ri int i=n;i>1;i--) printf("%lld %lld\n",i,i-1);
        }
    }
    return 0;
}