#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

#define il inline

constexpr int N=1e5+5;

struct EDGE
{
    int to,nxt,w;
};

int n,cnt;
EDGE e[N*2];
int dis[N],head[N];
bool vis[N];
queue<int>q;

il void add(int x,int y,int z)
{
    e[++cnt].to=y;
    e[cnt].nxt=head[x];
    e[cnt].w=z;
    head[x]=cnt;
}
void SPFA()
{
    for(int i=0;i<n;++i) dis[i]=1e9;
    dis[1]=1,q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=e[i].nxt)
        {
            if(dis[e[i].to]>dis[x]+e[i].w)
            {
                dis[e[i].to]=dis[x]+e[i].w;
                if(!vis[e[i].to]) q.push(e[i].to),vis[e[i].to]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i) add(i,(i+1)%n,1);
    for(int i=0;i<n;++i) add(i,(i*10)%n,0);
    SPFA();
    printf("%d\n",dis[0]);
    return 0;
}
