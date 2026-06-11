#include<cstdio>
#include<vector>
struct Edge{
    int l,r;
    long long c;
    Edge(){}
    Edge(int l,int r,long long c):l(l),r(r),c(c){}
};
std::vector<Edge>g[100005];
Edge check[200005];
int vis[100005];
long long value[100005];

void dfs(int u){
    vis[u] = 1;
    for(Edge e: g[u]){
        if(!vis[e.r]){
            value[e.r] = value[u]+e.c;
            dfs(e.r);
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; i++){
        int l,r; long long c;
        scanf("%d%d%lld",&l,&r,&c);
        g[l].push_back(Edge(l,r,c));
        g[r].push_back(Edge(r,l,-c));
        check[i] = Edge(l,r,c);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            value[i] = 0;
            dfs(i);
        }
    }
    int ok = 1;
    for(int i = 0; i < m; i++){
        int u = check[i].l, v = check[i].r;
        long long c = check[i].c;
        if(value[u]+c!=value[v]){
            ok = 0;
        }
    }
    if(ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}
