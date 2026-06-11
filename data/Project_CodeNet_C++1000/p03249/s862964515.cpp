#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;
const int maxn=101000;
int n;
ll d[maxn];
int size[maxn];
ll dis[maxn];
map<ll,int> mp;
vector<int> G[maxn];
ll sum=0;

void dfs1(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        dis[v]=dis[u]+1;
        dfs1(v,u);
    }
    sum+=dis[u];
}

void dfs2(int u,int fa){
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v==fa) continue;
        printf("%d %d\n",u,v);
        dfs2(v,u);
    }
}

int main(){
    //初始化
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&d[i]);
        mp[d[i]]=i;
    }
    sort(d+1,d+n+1);
    for(int i=1;i<=n;i++) size[i]=1;
    //构树
    for(int i=n;i>1;i--){
        int k=mp[d[i]];
        int tmp=n-2*size[k];
        //printf("%d   111\n",i);
        if(tmp<=0) {printf("-1\n");return 0;}
        ll ss=d[i]-tmp;
        //printf("%d    222\n",i);
        if(mp.count(ss)==0){printf("-1\n");return 0;}
        int pos=mp[ss];
        size[pos]+=size[k];
        G[pos].push_back(k);
        G[k].push_back(pos);
    }
   // printf("sbsbsb\n");
    dis[mp[d[1]]]=0;
    dfs1(mp[d[1]],-1);
    if(sum!=d[1]){
        printf("-1\n");
    }else{
        dfs2(1,-1);
    }
    return 0;
}
