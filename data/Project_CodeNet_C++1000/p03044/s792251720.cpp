#include <iostream>
#include <vector>
using namespace std;
using edge = pair<int, int>;
using graph = vector<vector<edge>>;
vector<int> color;

graph g;
int n;

//pはvの親
void dfs(int v, int p, int clr){
    color[v]= clr;
    for(auto e: g[v]){
        if(e.first == p){continue;}
        if(e.second & 1){dfs(e.first, v, 1-clr);}
        else{dfs(e.first, v, clr);}
    }
}

int main(){
    cin >> n;
    g.assign(n, vector<edge>());
    for(int i=0; i<n-1; ++i){
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    color.assign(n, 0);
    dfs(0, -1, 1);
    for(auto v: color){cout << v << endl;}
}