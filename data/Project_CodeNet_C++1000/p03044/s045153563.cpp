#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long;
using namespace std;

void dfs(int v, int p, vector<int> &color, vector<vector<pair<int,int>>> &G){
    for(auto nv : G[v]) if(nv.first != p){
        color[nv.first] = (color[v] + nv.second) % 2;
        dfs(nv.first,v,color,G);
    }
}

int main(){
    int n; cin >> n;

    vector<vector<pair<int,int>>> G(n);
    rep(i,n-1){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }

    vector<int> color(n,-1);
    color[0] = 0;
    dfs(0,-1,color,G);

    rep(i,n)  cout << color[i] << endl;
    return 0;
}