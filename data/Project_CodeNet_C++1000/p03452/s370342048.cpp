#include<stdio.h>
int f[100010],v[100010];
int fa(int a)
{
    if(f[a]==a)
        return a;
    int t=f[a];
    f[a]=fa(f[a]);
    v[a]+=v[t];
    return f[a];
}
bool connect(int x,int y,int d)
{
    int fx=fa(x);
    int fy=fa(y);
    if(fx!=fy)
    {
        f[fy]=fx;
        v[fy]=v[x]-v[y]+d;
    }
    else if(v[y]-v[x]!=d)
        return 1;
    return 0;
}
int main()
{
    int n,m,h=0,l,r,d;
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++)
        f[j]=j;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&d);
        h+=connect(l,r,d);//true失败
    }
    if(!h)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
