#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

//連結成分の個数を求める。

vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true;
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    Graph G(N + 1);
    for(int i = 0; i < M; i++){
        int x,y,z;
        cin >> x >> y >> z;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int count = 0;
    seen.assign(N, false);
    for(int v = 1; v < N + 1; v++){
        if(seen[v]) continue;
        dfs(G,v);
        count ++;
    }
    cout << count << endl;
}