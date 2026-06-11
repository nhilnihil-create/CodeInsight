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
    int a,b,c,d;
    a=read(), b=read(), c=read(), d=read();
    if(a+b>c+d) puts("Left");
    else if(a+b<c+d) puts("Right");
    else puts("Balanced");
    return 0;
}