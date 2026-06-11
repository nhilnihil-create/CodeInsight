#include <iostream>
#include <vector>
using namespace std;

void dfs(int vs, vector<int>& color, vector<vector<pair<int,int>>>& edge){
    for(auto vew : edge[vs]){
        int ve = vew.first;
        int w = vew.second;
        if(color[ve] >=0 )continue;
        color[ve] = color[vs]^(w&1);
        dfs(ve,color,edge);
    }
}


int main(void){
    int N;
    cin>>N;
    vector<vector<pair<int,int>>> edge(N,vector<pair<int,int>>(0));
    for(int i=0;i<N-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        edge[u].push_back(make_pair(v,w));
        edge[v].push_back(make_pair(u,w));
    }

    vector<int> color(N,-1);
    color[0] = 0;
    dfs(0, color, edge);

    for(auto c:color) cout<<c<<endl;
}