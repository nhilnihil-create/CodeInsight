#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> ans;
multiset<int> c;

void DFS(int v, int parent_v = -1){
    if(visited[v] == true) return;
    visited[v] = true;
    ans[v] = *prev(c.end());
    c.erase(prev(c.end()));

    bool leaf = true;
    for(int child_v : graph[v]){
        if(child_v == parent_v) continue;

        leaf = false;
        DFS(child_v, v);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    graph.resize(n);
    visited.resize(n);
    ans.resize(n);

    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int score = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        c.insert(x);
        score += x;
    }

    DFS(0);
    cout << score - ans[0] << endl;
    for(int i=0; i<n; i++){
        cout << ans[i];
        if(i == n-1) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}