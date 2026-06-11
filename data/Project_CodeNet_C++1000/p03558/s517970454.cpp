#include<cstdio>
#include<cstring>
struct edge
{
    int n,nxt,v;
    edge(int n,int nxt,int v)
    {
        this->n=n;
        this->nxt=nxt;
        this->v=v;
    }
    edge(){}
}e[200010];
int head[100010],ecnt=-1;
void add(int from,int to,int v)
{
    e[++ecnt]=edge(to,head[from],v);
    head[from]=ecnt;
}
int q[200100],l=100000,r=100000;
int dis[100100];
int main()
{
    memset(head,-1,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        add(i,(i+1)%n,1);
        add(i,i*10%n,0);
    }
    q[++r]=1;
    dis[1]=1;
    while(l<r)
    {
        int x=q[++l];
        for(int i=head[x];~i;i=e[i].nxt)
            if(dis[e[i].n]>dis[x]+e[i].v)
            {
                dis[e[i].n]=dis[x]+e[i].v;
                if(e[i].v)
                    q[++r]=e[i].n;
                else
                    q[l--]=e[i].n;
            }
    }
    printf("%d\n",dis[0]);
    return 0;
}
