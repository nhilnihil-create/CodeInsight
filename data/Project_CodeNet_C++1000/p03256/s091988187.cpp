//Problem B
#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,cnt,tot,dfn[N],low[N],st[N],tp,in[N];
char ch[N];
vector<int>e[N],E[N];
void tarjan(int v){
    dfn[v]=low[v]=++cnt;
    st[++tp]=v,in[v]=1;
    for(int i=0;i<(int)E[v].size();i++){
        int u=E[v][i];
        if(!dfn[u])tarjan(u),low[v]=min(low[v],low[u]);
        else if(in[u])low[v]=min(low[v],dfn[u]);
    }
    if(dfn[v]==low[v]){
        ++tot;int lust=0;
        while(lust!=v)lust=st[tp--],in[lust]=0;
    }
}
int main(){
    scanf("%d%d%s",&n,&m,ch+1);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b),e[b].push_back(a);
        if(ch[a]==ch[b])E[a].push_back(b+n),E[b].push_back(a+n);
        else E[a+n].push_back(b),E[b+n].push_back(a);
    }
    n<<=1;
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    if(tot==n)printf("No");else printf("Yes");
    //for(int i=1;i<=n;i++)for(int j=0;j<2;j++)if(!vis[i][j]){printf("try %d %d\n",i,j);
    //    ++cnt;if(dfs(i,j)){printf("Yes");for(int i=1;i<=n;i++){for(int j=0;j<2;j++)printf("%d ",vis[i][j]);printf("\n");}return 0;}
    //}printf("No");
    return 0;
}