#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=200005;
struct EDGE
{
    int v, w, next;
}e[maxn<<1];
int cnt;
int head[maxn]={};
void Add(int u, int v, int w){
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
int dp[2][maxn]={};
int n,ans;
void dfs(int u,int fa){
    //cout<<u<<endl;
    for(int i=head[u];i!=-1;i=e[i].next)if(e[i].v!=fa){
        int v=e[i].v,w=e[i].w;
        dfs(v,u);
        if(dp[0][v]+w>dp[0][u]){
            dp[1][u]=dp[0][u];
            dp[0][u]=dp[0][v]+w;
        }
        else if(dp[0][v]+w>dp[1][u]) dp[1][u]=dp[0][v]+w;
    }
    ans=max(ans,dp[0][u]+dp[1][u]);
    return;
}
int main()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));ans=0;cnt=0;
    memset(head,-1,sizeof(head));
    for(int i=0;i<n-1;i++){
        int u, v;
        scanf("%d%d",&u,&v);
        Add(u,v,1);
        Add(v,u,1);
    }
    dfs(1,-1);
    //cout<<ans<<endl;
    ans++;
    if(ans%3==0||ans%3==1)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}

