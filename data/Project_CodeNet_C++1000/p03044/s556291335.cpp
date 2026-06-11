#include<bits/stdc++.h>
#define ll long long
#define P pair<int ,int>
using namespace std;

struct edge{
    ll to ,cost;
};
int main(){
    int n;
    cin >> n;
    vector<vector<edge>> g(n);
    for(int i=0;i<(n-1);i++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back(edge{v ,w});
        g[v].push_back(edge{u ,w});
    }
    vector<int> color(n ,-1);
    color[0] = 0;

    queue<edge> que;
    que.push(edge{0 ,0});
    
    while(!que.empty()){
        edge e = que.front();
        que.pop();
        for(int i=0;i < (int)g[e.to].size() ;i++){
            ll nt = g[e.to][i].to ,nc = g[e.to][i].cost;
            if(color[nt] != -1) continue;
            if(nc%2 == 0) color[nt] = color[e.to];
            else {
                if(color[e.to] == 0) color[nt] = 1;
                else color[nt] = 0;
            }
            que.push(g[e.to][i]);
        }
    }

    for(int i=0;i<n;i++) cout << color[i] << endl;
}