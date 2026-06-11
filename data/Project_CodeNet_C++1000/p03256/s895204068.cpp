#include<queue>
#include<cstdio>
#include<cctype>
#include<vector>
const int N=200007;
int read(){int x=0,c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x;}
std::vector<int>e[N];std::queue<int>q;
int n,m,ans,vis[N],deg[N][2];char col[N];
int main()
{
    n=read(),m=read(),scanf("%s",col+1);
    for(int i=1,u,v;i<=m;++i) u=read(),v=read(),e[u].push_back(v),e[v].push_back(u),++deg[u][col[v]=='B'],++deg[v][col[u]=='B'];
    for(int i=1;i<=n;++i) if(!deg[i][0]||!deg[i][1]) ++ans,q.push(i),vis[i]=1;
    for(int u;!q.empty();)
    {
    u=q.front(),q.pop();
    for(int v:e[u]) if(!vis[v]&&!--deg[v][col[u]=='B']) ++ans,q.push(v),vis[v]=1;
    }
    puts(ans==n? "No":"Yes");
}