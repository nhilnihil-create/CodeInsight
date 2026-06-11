#include<cstdio>
#include<vector>
std::vector<int>g[100005];
std::vector<int>child[100005];
int in[100005];
int vis[100005];
int queue[100005];
int parent[100005];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n-1+m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[v].push_back(u);
        in[u]++;
    }
    int h = 0, t = -1;
    for(int i = 1; i <= n; i++){
        if(in[i]==0) queue[++t] = i;
    }
    while(h<=t){
        int u = queue[h++];
        for(int i = 0; i < (int)child[u].size(); i++){
            int v = child[u][i];
            if(!vis[v]){
                vis[v] = 1;
                parent[v] = u;
            }
        }
        for(int i = 0; i < (int)g[u].size(); i++){
            int v = g[u][i];
            in[v]--;
            child[v].push_back(u);
            if(in[v]==0) queue[++t] = v;
        }
    }
    for(int i = 1; i <= n; i++) printf("%d\n",parent[i]);
    return 0;
}
