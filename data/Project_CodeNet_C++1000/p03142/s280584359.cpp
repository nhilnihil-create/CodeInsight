#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<vector<int>> graph_inv(n);
    vector<int> in_degree(n);

    for(int i=0; i<n-1+m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph_inv[b].push_back(a);
        in_degree[b] += 1;
    }

    stack<int> deg0;
    for(int i=0; i<n; i++){
        if(in_degree[i] == 0) deg0.push(i);
    }

    vector<int> topo;
    while(deg0.empty() == false){
        int root = deg0.top(); deg0.pop();
        topo.push_back(root);

        for(int child : graph[root]){
            in_degree[child] -= 1;
            if(in_degree[child] == 0) deg0.push(child);
        }
    }

    vector<int> order(n);
    for(int i=0; i<n; i++){
        order[topo[i]] = i;
    }

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        for(int j : graph_inv[i]){
            if(ans[i] == 0 || order[ans[i]-1] < order[j]) ans[i] = j+1;
        }
        cout << ans[i] << endl;
    }
    return 0;
}