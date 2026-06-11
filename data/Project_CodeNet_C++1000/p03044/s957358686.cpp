#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;

vector<pair<int, int>> adj[MAX];
int n, u, v, w, vis[MAX], color[MAX];

int main(){
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    queue<int> queue;
    queue.emplace(1);
    vis[1] = 1;
    while(queue.size()){
        int cv = queue.front();
        queue.pop();
        for(auto p: adj[cv]){
            if (!vis[p.first]){
                if (p.second % 2 == 0)
                    color[p.first] = color[cv];
                else 
                    color[p.first] = 1 - color[cv];
                queue.emplace(p.first);
                vis[p.first] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << color[i] << "\n";
    return 0;
}