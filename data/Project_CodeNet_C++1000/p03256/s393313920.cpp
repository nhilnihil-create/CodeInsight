#include <bits/stdc++.h>
using namespace std;
const int maxn=200005*2;
int n,m,vis[maxn];
vector<int>G[maxn];
char str[maxn];
void dfs(int x){
  vis[x]=1;
  for(int v:G[x])if(~vis[v]){
    if(vis[v]==1){
      puts("Yes");
      exit(0);
    }else{
      dfs(v);
    }
  }
  vis[x]=-1;
}
int main(){
  //freopen("aa.in","r",stdin);
  scanf("%d%d%s",&n,&m,str+1);
  for(int i=1;i<=m;i++){
    int x,y;scanf("%d%d",&x,&y);
    // printf("e %d %d\n",x,y);
    if(str[x]==str[y]){
      G[x].push_back(n+y);
      G[y].push_back(n+x);
    }else{
      G[n+x].push_back(y);
      G[n+y].push_back(x);
    }
  }
  for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
  puts("No");
  return 0;
}
