#include <iostream>
#include<string.h>
#include<cstdio>
#include <stack>
#include <vector>
using namespace std;
#define INF 0x7ffffff
typedef long long ll;
const int maxn=1e5+10;
int pre[maxn];//存每个点的祖先
int dis[maxn];//这个点到祖先的距离
int findset(int x)
{
    if(x==pre[x])   return x;
    int root=findset(pre[x]);
    dis[x]=dis[pre[x]]+dis[x];//当前点x到根节点的距离=现在的距离+父节点到根节点的距离
    return pre[x]=root;//把每个子节点合并到他的祖先
}
bool unionset(int x,int y,int w)
{
    int fx=findset(x),fy=findset(y);
    if(fx==fy)
        return w==dis[y]-dis[x];
    pre[fy]=fx;
    dis[fy]=dis[x]+w-dis[y];
    return true;
}
int n,m;
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
    pre[i]=i;
   bool lose=true;
   for(int i=0;i<m;i++)
   {
       int x,y,w;
   scanf("%d%d%d",&x,&y,&w);
        if(lose)
       lose=unionset(x,y,w);
   }
   if(lose) printf("Yes\n");
   else     printf("No\n");
}
