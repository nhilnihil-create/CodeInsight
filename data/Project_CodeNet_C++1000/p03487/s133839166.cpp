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
int n,a[N],res;
map<int,int> Q;
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++)
    {
        a[i]=read();
        Q[a[i]]++;
    }
    for(ri map<int,int>::iterator s=Q.begin();s!=Q.end();s++)
    {
        int x=(s->first), y=s->second;
        if(y>=x) res+=y-x;
        else res+=y;
    }
    printf("%lld\n",res);
    return 0;
}