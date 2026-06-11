/*Program from Luvwgyx*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
struct node{int to,nxt;}e[maxn<<1];
int n,tot,mx,root,head[maxn],dep[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
void add(int u,int v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;}

void dfs(int x,int fa){
    if(dep[x]>mx){mx=dep[x];root=x;}
    for(int i=head[x],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
        if(v!=fa)dep[v]=dep[x]+1,dfs(v,x);
}
int main(){
    n=read();
    for(int i=2;i<=n;i++){int u=read(),v=read();add(u,v);add(v,u);}
    dfs(1,0);mx=0;memset(dep,0,sizeof(dep));
    dep[root]=1;dfs(root,0);
    if(mx%3==2)puts("Second");
    else puts("First");
    return 0;
}
