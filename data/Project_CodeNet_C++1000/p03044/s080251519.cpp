#include<bits/stdc++.h>

using namespace std;

vector<int> color;

void dfs(vector<vector<pair<int,int>>> &g,int v,int cur = 0){
    for(int i = 0;i < g[v].size();i++){
        if(color[g[v][i].first] != -1)continue;
        if(g[v][i].second % 2 == 0){
            color[g[v][i].first] = cur;
            dfs(g,g[v][i].first,cur);
        }else{
            color[g[v][i].first] = 1-cur;
            dfs(g,g[v][i].first,1-cur);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0;i < n-1;i++){
        int k;pair<int,int> p;
        cin >> k >> p.first >> p.second;
        k-=1;p.first -= 1;
        graph[k].push_back(p);
        swap(k,p.first);
        graph[k].push_back(p);
    }
    color.assign(n,-1);
    for(int v = 0;v < n;v++){
        if(color[v] != -1)continue;
        if(v == 0){
            dfs(graph,v);
            continue;
        }
        dfs(graph,v,color[v]);
    }
    for(auto a : color)cout << a << endl;
    return 0;
}
