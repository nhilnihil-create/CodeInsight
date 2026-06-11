#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i = (a);i <= (b);++i)
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
ll qpow(ll a,ll b){ll res = 1;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct graph
{
    int head[maxn],nxt[maxn<<1],to[maxn<<1],w[maxn<<1],sz;
    void init(){memset(head,-1,sizeof(head));}
    graph(){init();}
    void push(int a,int b,int c=0){nxt[sz]=head[a],to[sz]=b,w[sz]=c,head[a]=sz++;}
    int& operator[](const int a){return to[a];}
}g;
char s[maxn];
int vis[maxn][2];
void dfs(int now,bool flag)
{
    vis[now][flag]=1;
    for(int i = g.head[now];~i;i = g.nxt[i]){
        if(flag==1){
            if(s[g[i]]!=s[now]){
                if(!vis[g[i]][!flag]){
                    dfs(g[i],!flag);
                }
                if(vis[g[i]][!flag]==1){
                    printf("Yes\n");
                    exit(0);
                }
            }
        }
        else{
            if(s[g[i]]==s[now]){
                if(!vis[g[i]][!flag]){
                    dfs(g[i],!flag);
                }
                if(vis[g[i]][!flag]==1){
                    printf("Yes\n");
                    exit(0);
                }
            }
        }
    }
    vis[now][flag]=2;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i = 1,a,b;i <= m;++i){
        scanf("%d%d",&a,&b);
        g.push(a,b),g.push(b,a);
    }
    for(int i = 1;i <= n;++i){
        if(!vis[i][0])dfs(i,0);
        if(!vis[i][1])dfs(i,1);
    }
    printf("No\n");
    return 0;
}