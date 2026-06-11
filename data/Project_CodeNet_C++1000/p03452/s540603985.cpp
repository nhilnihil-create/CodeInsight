#include<stdio.h>
#include<cmath>
#include<math.h>
#include<string.h>
using namespace std;
#define maxn 100010
#define MAX 1e15
#define INF 0x3f3f3f3f
struct node
{
    int to,next;
    long long  w;
}edge[200000*2+100];
bool flag;//无负环
int k;
int head[maxn],visit[maxn];
long long  dis[maxn];

void add_edge(int from,int to,long long  weight)
{

    edge[k].to=to;
    edge[k].w=weight;
    edge[k].next=head[from];
    //printf("edge[%2d].to=%-4d edge[%2d].w=%lld edge[%2d].next=%-4d head[%2d]=%-4d\n",k,edge[k].to,k,edge[k].w,k,edge[k].next,from,k);
    head[from]=k++;
}
void init_spfa()
{
    for(int i=0;i<=100005;i++)
        dis[i]=1e15;
    memset(visit,0,sizeof(visit));
    memset(head,-1,sizeof(head));
    k=0;
    flag=true;
}
void SPFA_dfs(int u)
{
    visit[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int to=edge[i].to;
        if(dis[u]+edge[i].w<dis[to])
        {
            //printf("i=%d  edge[%d]=%.4lf\n",i,i,edge[i].w);
            if(visit[to]||!flag)
            {
                flag=false;//有负环
                break;
            }
            dis[to]=dis[u]+edge[i].w;
            SPFA_dfs(to);
        }
    }
    visit[u]=0;
}

bool SPFA(int n)
{
    for(int i=1;i<=n;i++)
    {
        //printf("i=%d\n",i);
        SPFA_dfs(i);
        if(!flag)
            return flag;
    }
    return true;
}
int main()
{
    int N,M;
    int l,r;
    long long d;
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        init_spfa();
        while(M--)
        {
            scanf("%d%d%lld",&l,&r,&d);
            add_edge(l,r,d);
            add_edge(r,l,-d);
        }
        if(SPFA(N))
            printf("Yes\n");
        else
            printf("No\n");
    }
}
