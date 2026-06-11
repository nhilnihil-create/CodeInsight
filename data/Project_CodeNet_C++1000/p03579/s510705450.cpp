#include <bits/stdc++.h>
using namespace std;
using Edge = pair<int,int>;
using Graph = vector<vector<int> >;
#define INF 1000000007
typedef long long ll;


vector<int> color;
bool dfs(const Graph &G,int v,int c = 0){
    color[v] = c;
    for(auto e : G[v]){

        /* 
        if(color[e] != -1){
            if(color[e] == c)return false;
            else continue;
        }
        if(!dfs(G,e, 1-c) )return false;*/

    if(color[e] == c){
            return false;
        }
        if(color[e] == -1 && !dfs(G,e, 1-c) ){
            return false;
        }

    }
    return true;
}

int main(){
    ll N,M;cin >> N >> M;
    Graph G(N);
    color.assign(N,-1);
    ll res = 0;
    ll w = 0,b = 0;
    for(int i = 0 ; i < M ; i++){
        int u,v;cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // v が探索済みだったらスルー
        if (!dfs(G, v)) is_bipartite = false;
    }

    if(is_bipartite){
         for(int i=0; i<N; i++){
            if(color[i] == 1){
                b++;
            }else if(color[i] == 0){
                w++;
            }
        }
        cout << b*w-M << endl;
    }else{
        cout << ((N*(N-1))/2)-M << endl;//完全グラフ
    }
    return 0;
}