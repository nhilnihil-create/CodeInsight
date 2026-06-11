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
    int a,b;
    a=read(), b=read();
    if(a==1&&b==1) puts("1");
    else if(a==1 || b==1) printf("%lld\n",max(a,b)-2);
    else printf("%lld\n",(a-2)*(b-2));
    return 0;
}