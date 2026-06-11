#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

vector<vector<int> > g;

P bfs(int s){
    vector<int> dist(g.size(),-1);
    queue<int> que;
    que.push(s);
    dist[s] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(auto u : g[v]){
            if(dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            que.push(u);
        }
    }
    int dmax = 0, idx = -1;
    for(int i=0;i<int(g.size());i++){
        if(dist[i] > dmax){
            dmax = dist[i];
            idx = i;
        }
    }
    return P(idx, dmax);
}

int main(){
    int n;
    cin >> n;
    g.resize(n);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int u = 0, v, dmax = 0;
    for(int i=0;i<10;i++){
        auto p = bfs(u);
        v = u;
        u = p.first;
        dmax = p.second;
    }
    cout << (dmax%3 == 1 ? "Second" : "First") << endl;
    return 0;
}