#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

void dfs(int v, vector<vector<int>> &G, vector<bool> &used){
    used[v] = true;
    for(auto nv : G[v]){
        if(used[nv] == false) dfs(nv, G, used);
    }
    return;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = 0;
    vector<bool> used(n,false);
    rep(i,n){
        if(used[i] == false){ dfs(i, G, used); ans++; }
    }
    cout << ans << endl;
}