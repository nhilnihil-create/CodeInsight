#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[200005];
int dist[200005];

int dfs(int x,int par){
    for(int i=0;i<(int)adj[x].size();i++){
        if(adj[x][i]==par){
            continue;
        }
        dist[adj[x][i]]=dist[x]+1;
        dfs(adj[x][i],x);
    }
}

int main(){
    scanf("%d",&n);
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b); a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,-1);
    int maxi=0;
    for(int i=1;i<n;i++){
        if(dist[maxi]<dist[i])maxi=i;
    }
    memset(dist,0,sizeof(dist));
    dfs(maxi,-1);
    int diameter=0;
    for(int i=0;i<n;i++)diameter=max(diameter,dist[i]);
    bool dp[diameter+5];
    dp[0]=1; dp[1]=0;
    for(int i=2;i<=diameter;i++){
        if(dp[i-1]&&dp[i-2]){
            dp[i]=0;
        }else{
            dp[i]=1;
        }
    }
    if(dp[diameter])printf("First");
    else printf("Second");
}
