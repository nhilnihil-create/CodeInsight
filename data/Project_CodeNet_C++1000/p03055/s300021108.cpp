#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> d;
void DFS(int v, int previous_v){
    for(int adjacent : graph[v]){
        if(adjacent == previous_v) continue;

        d[adjacent] = d[v] + 1;
        DFS(adjacent, v);
    }
}

int main(){
    int n;
    cin >> n;

    graph.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    d.assign(n,0);
    DFS(0, -1);
    int furthest, dist = 0;
    for(int i=0; i<n; i++){
        if(dist < d[i]){
            furthest = i;
            dist = d[i];
        }
    }
    d.assign(n,0);
    DFS(furthest, -1);
    int diameter = 0;
    for(int i=0; i<n; i++){
        if(diameter < d[i]){
            diameter = d[i];
        }
    }

    vector<bool> ans(diameter+1);
    ans[0] = true;
    ans[1] = false;
    for(int i=2; i<=diameter; i++){
        ans[i] = (!ans[i-1]) | (!ans[i-2]);
    }
    if(ans[diameter] == true)  cout << "First"  << endl;
    if(ans[diameter] == false) cout << "Second" << endl;
    return 0;
}