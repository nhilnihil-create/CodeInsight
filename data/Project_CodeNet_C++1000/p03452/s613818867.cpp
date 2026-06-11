#include <bits/stdc++.h>
using namespace std;
int f[100010],d[100010];
int findd(int x)
{
    if(f[x]==x) return x;
    int a=f[x];
    int b=findd(f[x]);
    d[x]+=d[a];
    f[x]=b;
    return b;
}
bool unit(int x,int y,int c)
{
    int fx=findd(x);
    int fy=findd(y);
    if(fx==fy)
    {
        if(d[y]-d[x]==c) return 1;
        else return 0;
    }
    f[fy]=fx;
    d[fy]=d[x]+c-d[y];
    return 1;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int flag=0;
        int l,r,d;
        for(int i=1;i<=n;i++)f[i]=i;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&l,&r,&d);
            if(!unit(l,r,d))
            {
                flag=1;
            }
        }
        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
