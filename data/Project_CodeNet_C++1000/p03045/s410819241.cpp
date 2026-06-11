#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<bool> seen;
void dfs(int v){
    if(!seen[v]) return;
    seen[v]=false;
    for(auto nv:g[v]){
        if(!seen[nv]) continue;
        dfs(nv);
    }
}

int main(){
    cin>>n>>m;
    g.resize(n);
    seen.assign(n,true);
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res=0;
    for(int i=0;i<n;++i){
        if(!seen[i]) continue;
        dfs(i);
        ++res;
    }

    cout<<res<<endl;
}