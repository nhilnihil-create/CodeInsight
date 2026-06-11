#include <iostream>
using namespace std;

const int maxn=1000005;

int fa[maxn];
int dis[maxn];

int Find(int x)
{
    if(fa[x]==x)
        return x;
    int r=Find(fa[x]);
    dis[x]=dis[fa[x]]+dis[x];
    return fa[x]=r;
}

int Union(int x,int y,int z)
{
    int fx=Find(x);
    int fy=Find(y);

    if (fx==fy)
        return z==dis[y]-dis[x];
    fa[fy]=fx;
    dis[fy]=dis[x]+z-dis[y];
    return 1;
}

int main()
{
    int n,m;
    int flag= 1;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        fa[i]=i;
    for (int i=1;i<=m;i++)
    {
        int l,r,d;
        cin>>l>>r>>d;
        if (flag)
            flag=Union(l,r,d);
    }
    if (flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
