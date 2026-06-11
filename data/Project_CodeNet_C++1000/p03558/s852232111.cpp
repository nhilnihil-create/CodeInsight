#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
struct node{
    int v,nxt,cost;
}edge[N<<1];
int head[N],k,tot;
int q[N*8],l,r,u,v;
int dist[N];
void addEdge(int u,int v,int val) {
    edge[++tot].v=v;
    edge[tot].cost=val;
    edge[tot].nxt=head[u];
    head[u]=tot;
}
int main() {
    //freopen("out.txt","w",stdout);
    scanf("%d",&k);
    for (int i=0;i<k;++i) {
        addEdge(i,i+1==k?0:i+1,1);
        addEdge(i,i*10%k,0);
        dist[i]=N;
    }
    dist[1]=0;
    l=-1;
    r=0;
    q[0]=1;
    while (l<r) {
        u = q[++l];
        for (int i=head[u];i;i=edge[i].nxt) {
            v=edge[i].v;
            if (dist[u]+edge[i].cost<dist[v]) {
                dist[v]=dist[u]+edge[i].cost;
                q[++r]=v;
            }
        }
    }
    printf("%d\n",dist[0]+1);
    return 0;
}
