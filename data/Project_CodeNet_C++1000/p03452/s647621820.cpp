#include<cstdio>
int n,m,fa[100005],dis[100005];
bool ok=1;
int find(int x){
    if(fa[x]!=x){
        int nf=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[nf];
    }
    return fa[x];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        int l,r,d;
        scanf("%d%d%d",&l,&r,&d);
        int rl=find(l),rr=find(r);
        if(rl==rr&&dis[l]-dis[r]!=d)
            ok=0;
        if(rl!=rr){
            fa[rl]=rr;
            dis[rl]=d+dis[r]-dis[l];
        }
    }
    if(ok)printf("Yes");
    else printf("No");
    return 0;
} 