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
int n,H,book[N];
struct Node
{
    int a,b,id;
}q[N];
inline bool cp(Node x,Node y) { return x.a==y.a?x.b<y.b:x.a>y.a; }
inline bool cp1(Node x,Node y) { return x.b>y.b; }
signed main()
{
    int res=0;
    n=read(), H=read();
    for(ri int i=1;i<=n;i++) q[i].a=read(), q[i].b=read(), q[i].id=i;
    sort(q+1,q+1+n,cp);
    book[q[1].id]=1;
    int qwq=q[1].a;
    int tt=q[1].b;
    sort(q+1,q+1+n,cp1);
    for(ri int i=1;i<=n;i++)
    {
        if(book[q[i].id]) continue;
        if(q[i].b<qwq) break;
        H-=q[i].b; res++;
        if(H<=0) { printf("%lld\n",res); return 0; }
    }
    if(qwq>=tt)
    {
        printf("%lld\n",res+(H-1)/qwq+1);
        return 0;
    }
    else
    {
        H-=tt; res++;
        if(H<=0) { printf("%lld\n",res); return 0; }
        printf("%lld\n",res+(H-1)/qwq+1);
    }
    return 0;
}