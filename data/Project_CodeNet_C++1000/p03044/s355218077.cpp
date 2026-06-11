#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=1e18;

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int n):par(n),rank(n,0){
        for(int i=0;i<n;i++) par[i]=i;
    }
    int root(int x){
        if(par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry) return ;
        if(rank[rx]<rank[ry]){
            par[rx]=ry;
        }else par[ry]=rx;
        if(rank[rx]==rank[ry]) rank[ry]++;
    }
    bool same(int x,int y){
        return root(x)==root(y);
    }
};

struct edge{
    int to;
    ll cost;
};

int n;
vector<vector<edge> > Tree(MAXN);
vector<int> color(MAXN,-1);

void dfs(int u,int c){
    color[u]=c;
    for(auto e:Tree[u]){
        if(color[e.to]!=-1) continue;
        if(e.cost%2==0) dfs(e.to,c);
        else dfs(e.to,1-c);
    }
    return ;
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w;cin>>u>>v>>w;
        u--;v--;
        Tree[u].push_back(edge{v,w});
        Tree[v].push_back(edge{u,w});
    }
    dfs(0,1);
    for(int i=0;i<n;i++){
        cout<<color[i]<<endl;
    }
    return 0;
}