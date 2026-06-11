#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
struct edge{
    int u,v,next;
}E[maxn];
int tot=0,head[maxn];
void addedge(int u,int v){
    E[++tot].v=v;
    E[tot].u=u;
    E[tot].next=head[u];
    head[u]=tot;
}
int p;
int c[maxn],value[maxn];
void dfs(int u){
//    printf("u=%d\n",u);
    value[u]=c[p--];
    for(int i=head[u];i;i=E[i].next){
        int v=E[i].v;
        if(!value[v]){
            dfs(v);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    sort(c+1,c+1+n);
    p=n;
    dfs(1);
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        int u=E[i<<1].u;
        int v=E[i<<1].v;
        ans=ans+min(value[u],value[v]);
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++){
        printf("%d ",value[i]);
    }
}
