//2019.5.13 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-10
#define RG register
inline int read() {
    res s=0,ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline LL Read() {
    RG LL s=0;
    res ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s;
}
inline void swap(res &x,res &y) {
    x^=y^=x^=y;
}
const int N=2e5+10;
namespace MAIN {
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N<<1];
    int n,head[N],cnt,sg[N],dep[N],mx,ID;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
        edge[++cnt]=E(head[v],u),head[v]=cnt;
    }
    void dfs(res x,res fax,res depx){
        dep[x]=depx;
        if(dep[x]>dep[mx])mx=x;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            if(tox==fax)continue;
            dfs(tox,x,depx+1);
        }
    }
    inline void MAIN(){
        n=read(),sg[1]=1,sg[2]=0;
        for(res i=1;i<=n;i++)head[i]=-1;
        for(res i=3;i<=n;i++)sg[i]=min(sg[i-1],sg[i-2])^1;
        for(res i=1;i<n;i++){
            res u=read(),v=read();
            addedge(u,v);
        }
        dfs(1,0,1),ID=mx,mx=0,dfs(ID,0,1),puts(sg[dep[mx]]?"First":"Second");
    }
}
int main() {
//    srand((unsigned)time(NULL));
//    freopen("graph.in","r",stdin);
//    freopen("graph.out","w",stdout);
    MAIN::MAIN();
    return 0;
}