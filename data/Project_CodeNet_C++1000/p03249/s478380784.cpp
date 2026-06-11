#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <assert.h>
using namespace std;
typedef long long LL;
const int N=100000+10;
int n,sz[N]; 
pair<LL,LL> d[N];
vector<LL> g[N];
bool cmp(pair<LL,LL> p1,pair<LL,LL> p2){
    return p1.second>p2.second;
}
map<LL,LL> mp;
vector< pair<LL,LL> > res;
int dep[N]; LL sum=0;
void prt(int u,int p){
    for(auto v:g[u]){
        if(v==p)continue;
        res.push_back(make_pair(u,v));
        dep[v]=dep[u]+1; sum+=dep[v];
        prt(v,u);
    }
}
int main() {
    scanf("%d",&n); 
    for(int i=1;i<=n;i++){
        d[i].first=i; 
        scanf("%lld",&d[i].second);
        mp[d[i].second]=i;
        sz[i]=1;
    }
    sort(d+1,d+1+n,cmp);
    for(int i=1;i<n;i++){
        LL tmp=d[i].second;
        LL nex=tmp-(n-2*sz[d[i].first]);
        if(mp[nex]==0||nex>=tmp){
            return !printf("-1\n");
        }
        int u=mp[nex];
        int v=d[i].first;
        g[u].push_back(v); g[v].push_back(u);
        sz[u]+=sz[v];
    }
    prt(d[n].first,d[n].first);
    if(sum != d[n].second) return !printf("-1\n");
    if(res.size()==n-1){
        for(auto p: res) printf("%lld %lld\n", p.first, p.second);
    } else {
        printf("-1\n");
    }
}


