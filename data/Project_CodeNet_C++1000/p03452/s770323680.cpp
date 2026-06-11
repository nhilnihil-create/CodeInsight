#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int mx = 1e5 + 5;
int vis[mx], val[mx];
int n, m;
vector<pii> G[mx];

bool dfs(int x){
    vis[x] = 1;
    for(pii u : G[x]){
        if(vis[u.first]){
            if(val[u.first] != val[x] + u.second) return false;
            else continue;
        }
        val[u.first] = val[x] + u.second;
        if(!dfs(u.first)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b, w; i < m; i++){
        cin >> a >> b >> w;
        G[a].emplace_back(b,w);
        G[b].emplace_back(a,-w);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i] && !dfs(i)){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}