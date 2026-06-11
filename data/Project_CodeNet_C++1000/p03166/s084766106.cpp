#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(1e5+1, vector<int>(0));
vector<int> path (1e5+1, -1);

int dfs(int v){
    if (path[v]!=-1) return path[v];
    else{
       path[v] = 0;
       for (auto i:G[v]){
          path[v] = max(path[v], dfs(i)+1); 
       }
    } 
    return path[v];
}

int main(){
    int n, m; cin >> n >> m;
    for (int i=1; i<=m; i++){
        int a, b; cin >> a >> b;
        G[a].push_back(b);
    }    

    int max_path = 0;
    for (int i=1; i<=n; i++){
        if (path[i]==-1){
            max_path = max(max_path, dfs(i));
        }
    }
    cout << max_path << endl;
    
    return 0;
}