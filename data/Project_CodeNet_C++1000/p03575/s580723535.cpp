#include <bits/stdc++.h>
using namespace std;

int n, m;
bool G[50][50], seen[50];

void dfs(int v){
    seen[v] = true;
    for(int i = 0; i < n; i++){
        if(seen[i]) continue;
        if(!G[v][i]) continue;
        dfs(i);
    }
}

int main(){
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
        G[a[i]][b[i]] = G[b[i]][a[i]] = true;
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        G[a[i]][b[i]] = G[b[i]][a[i]] = false;
        for(int j = 0; j < n; j++) seen[j] = false;
        dfs(0);
        bool ok = false;
        for(int j = 0; j < n; j++){
            if(!seen[j]) ok = true;
        }
        if(ok) ans++;
        G[a[i]][b[i]] = G[b[i]][a[i]] = true;
    }
    cout << ans << endl;
}