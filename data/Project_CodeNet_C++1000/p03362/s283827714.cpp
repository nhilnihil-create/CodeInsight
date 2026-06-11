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
int n;
inline bool Check(int x)
{
    for(ri int i=2;i*i<=x;i++) if(x%i==0) return 0;
    return 1;
}
signed main()
{
    n=read();
    for(ri int i=11;n;i+=10)
    {
        if(Check(i)) printf("%lld ",i), n--;
    }
    puts("");
    return 0;
}