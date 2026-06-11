#include <bits/stdc++.h>
#define LL long long int
#define maxn 100000
using namespace std;

int f[maxn+5];
int v[maxn+5];

int getfa(int x)
{
    if(f[x]==x)
    return x;
    int t=f[x];
    f[x]=getfa(f[x]);
    v[x]=v[x]+v[t];
    return f[x];
}

void link(int x,int y,int d)
{
    int fx,fy;
    fx=getfa(x);
    fy=getfa(y);
    if(fx!=fy)
    {
        f[fy]=fx;
        v[fy]=v[x]+d-v[y];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    f[i]=i;
    int flag=1;
    int l,r,d;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&l,&r,&d);
        if(getfa(l)!=getfa(r))
        {
            link(l,r,d);
        }
        else
        {
            ///printf("%d %d\n",v[l],v[r]);
            if(-v[l]+v[r]!=d)
                flag=0;
        }
    }

    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
