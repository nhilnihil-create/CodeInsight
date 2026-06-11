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
int n,a[N],qwq=1e9;
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++)
    {
        a[i]=read();
        int cnt=0;
        int x=a[i];
        while(x%2==0) x/=2, cnt++;
        qwq=min(qwq,cnt);
    }
    printf("%lld\n",qwq);
    return 0;
}