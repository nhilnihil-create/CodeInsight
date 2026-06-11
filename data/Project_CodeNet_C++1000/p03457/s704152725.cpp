#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=1000010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
signed main()
{
    int n,lx,ly;
    n=read();
    lx=ly=0;
    int flg=1;
    int lt=0;
    for(ri int i=1;i<=n;i++)
    {
        int t,x,y;
        t=read(), x=read(), y=read();
        if(!flg) continue;
        if(t-lt<abs(lx-x)+abs(ly-y) || (t-lt)%2!=(abs(lx-x)+abs(ly-y))%2) { flg=0; continue; }
        lx=x, ly=y, lt=t;
    }
    (flg)?puts("Yes"):puts("No");
    return 0;
}