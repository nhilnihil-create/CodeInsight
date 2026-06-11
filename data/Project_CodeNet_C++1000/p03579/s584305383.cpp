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
typedef pair<int,ii> P;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;

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

ll n,m;
vector<vector<int> > G(MAXN);
vector<int> cl(MAXN,0);

bool dfs(int u,int c){
    cl[u]=c;
    for(auto v:G[u]){
        if(cl[v]==c) return false;
        if(cl[v]==0&&!dfs(v,-c)) return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(!dfs(0,1)){
        cout<<n*(n-1)/2-m<<endl;
        return 0;
    }
    ll b=0,w=0;
    for(int i=0;i<n;i++){
        if(cl[i]==1) b++;
        else w++;
    }
    cout<<b*w-m<<endl;
    return 0;
}