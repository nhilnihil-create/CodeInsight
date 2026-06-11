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
    int n,a,b;
    int res=0;
    n=read(), a=read(), b=read();
    for(ri int i=1;i<=n;i++)
    {
        int x=i;
        int qwq=0;
        while(x) qwq+=x%10, x/=10;
        if(qwq>=a&&qwq<=b) res+=i;
    }
    printf("%lld\n",res);
    return 0;
}