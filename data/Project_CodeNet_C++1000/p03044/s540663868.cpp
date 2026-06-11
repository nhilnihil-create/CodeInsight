#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> dep;

void dfs(vector<vector<pair<int,int>>>& g, int v){
    for(int i = 0; i < g[v].size(); i++) {
        int nv=g[v][i].first;
        int len=g[v][i].second;
        if(dep[nv]!=-1) continue;
        dep[nv]=dep[v]+len;
        dfs(g,nv);
    }
}


//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < n-1; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        --u;
        --v;
        w%=2;
        g[u].emplace_back(make_pair(v,w));
        g[v].emplace_back(make_pair(u,w));
    }
    dep.assign(n,-1);
    dep[0]=0;
    dfs(g,0);
    for(int i = 0; i < n; i++) {
        if(dep[i]%2) cout << "0" << "\n";
        else cout << "1" << "\n";
    }



    return 0;
}