/*Unknown_Ghost*/
/*AGC033C Removing Coins*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

#define LL long long
#define MAXN 200000
#define MOD 998244353
#define Pr pair<int,int>
#define X first
#define Y second
#define mem(x,p) memset(x,p,sizeof(x))

LL read(){
  LL x=0,F=1;char c=getchar();
  while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
  while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
  return x*F;
}
int add(int x,int y){return (x+y>=MOD)?x+y-MOD:x+y;}
int dec(int x,int y){return (x-y<0)?x-y+MOD:x-y;}
int mul(int x,int y){return 1LL*x*y%MOD;}

int n,D,pos;
vector<int> G[MAXN+5];
void dfs(int x,int fa,int dis){
    if(dis>D){
        D=dis;pos=x;
    }
    for(int i=0;i<G[x].size();i++){
        int nxt=G[x][i];
        if(nxt==fa)continue;
        dfs(nxt,x,dis+1);
    }
}
int main()
{
    n=read();
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0,1);
    D=0;
    dfs(pos,0,1);
    printf("%s",(D%3==2)?"Second":"First");
}
