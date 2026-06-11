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
#include<tuple>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=1e5;

struct edge{
    int to,cost;
};

int n;
vector<vector<edge> > G(MAXN);
vector<int> color(MAXN,-1);

void dfs(int u,int c){
    color[u]=c;
    for(auto e:G[u]){
        if(color[e.to]!=-1) continue;
        if(e.cost%2==0) dfs(e.to,c);
        else dfs(e.to,1-c);
    }
    return;
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        G[u].push_back(edge{v,w});
        G[v].push_back(edge{u,w});
    }
    dfs(0,0);
    for(int i=0;i<n;i++){
        cout<<color[i]<<endl;
    }
    return 0;
}