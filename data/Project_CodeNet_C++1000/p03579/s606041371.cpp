#include<bits/stdc++.h>
using namespace std;
int n,m,to[200001],nxt[200001],tot,col[100001],head[100001],sum[3],cnt;
long long ans;
bool vis[100001],flag;
void add(int u,int v){to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
void dfs(int x,int color){
    ++cnt;
    col[x]=color;
    sum[color]++;
    vis[x]=true;
    for(int i=head[x];i;i=nxt[i]){
        if(!vis[to[i]])dfs(to[i],3-color);
        else if(col[x]==col[to[i]])flag=true;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        dfs(i,1);
        if(!flag)ans+=1LL*sum[1]*sum[2];
        else ans+=1LL*cnt*(cnt-1)/2;
        sum[1]=sum[2]=flag=cnt=0;
    }
    printf("%lld\n",ans-m);
    return 0;
}