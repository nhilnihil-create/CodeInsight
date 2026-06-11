#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn=100005;
int n,sz[Maxn],id[Maxn];
ll d[Maxn],sum;
vector<pair<int,int>>edge;
vector<int>son[Maxn];
void dfs1(int x,int dis=0){
    sum+=dis;
    for(int y:son[x])
        dfs1(y,dis+1);
}
void dfs2(int x,ll sum){
    if(sum!=d[x]){
        cout<<"-1\n";
        exit(0);
    }
    for(int y:son[x])
        dfs2(y,sum+n-2*sz[y]);
}
int main(){
    scanf("%d",&n);
    map<ll,int>Map;
    for(int i=1;i<=n;i++)scanf("%lld",&d[i]),Map[d[i]]=i;
    for(int i=1;i<=n;i++)id[i]=i;
    sort(id+1,id+n+1,[](int x,int y){return d[x]>d[y];});
    for(int i=1;i<n;i++){
        int x=id[i];
        sz[x]+=1;
        ll v=d[x]-n+2*sz[x];
        int y=Map[v];
        if(!y){
            cout<<"-1\n";
            return 0;
        }
        sz[y]+=sz[x];
        son[y].push_back(x);
        edge.emplace_back(x,y);
    }
    dfs1(id[n]);
    dfs2(id[n],sum);
    for(auto i:edge)
        cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}