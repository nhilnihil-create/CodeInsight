#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e5+10;
struct edge{
    int to,next,w;
}e[maxn*10];
int head[maxn],cnt;
void add(int u,int v,int w){
    e[cnt].to=v;e[cnt].next=head[u];e[cnt].w=w;head[u]=cnt++;
}
int dis[maxn];
int dij(int s){
    priority_queue<pair<int,int> >q;
    memset(dis,inf,sizeof(dis));dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int now=q.top().second;int d=q.top().first;q.pop();
        if(d>dis[now])continue;
        for(int i=head[now];~i;i=e[i].next){
            int v=e[i].to;
            if(dis[v]>dis[now]+e[i].w){
                dis[v]=dis[now]+e[i].w;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
    return dis[0];
}
int main()
{
    int n;
    cin>>n;
    memset(head,-1,sizeof(head));
    for(int i=0;i<n;i++){
        add(i,(i+1)%n,1);
        add(i,(i*10)%n,0);
    }
    cout<<1+dij(1)<<endl;
}
