#include<bits/stdc++.h>
const long long maxn=1e5+100;
using namespace std;
long long n,m,k,t,f[maxn],x,y,d[maxn];bool le;
int getf(int u)
{
    int k;
    if(f[u]==u)
        return u;
    k=f[u];
    f[u]=getf(f[u]);
    d[u]=d[u]+d[k];
    return f[u];
}
void jia(int x,int y,int k)
{
    int i,j;
    i=getf(x);
    j=getf(y);
    f[j]=i;
    d[j]=d[x]-d[y]-k;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;++i)
        f[i]=i;
    for(int i=1;i<=m;++i)
    {
        scanf("%lld%lld%lld",&x,&y,&k);
        if(getf(x)!=getf(y))
            jia(y,x,k);
        else
            if(d[y]-d[x]!=k)
        {
            le=1;
        }
    }
    if(le)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
