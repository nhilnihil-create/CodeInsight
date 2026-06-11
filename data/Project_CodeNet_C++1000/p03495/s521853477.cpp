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
int n,K,a[N],res,book[N];
int w[N],cnt,qwq;
signed main()
{
    n=read(), K=read();
    for(ri int i=1;i<=n;i++) a[i]=read(), book[a[i]]++;
    for(ri int i=1;i<=n;i++)
    {
        if(book[i]) qwq++, w[++cnt]=book[i];
    }
    sort(w+1,w+1+cnt);
    int now=0;
    while(qwq>K)
    {
        qwq--;
        res+=w[++now];
    }
    printf("%lld\n",res);
    return 0;
}