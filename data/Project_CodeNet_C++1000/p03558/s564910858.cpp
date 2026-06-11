#include <iostream>
#include <vector>
#include <queue>

struct edge{
    int to, cost;
};

using namespace std;

typedef pair<int, int> P;

vector<edge> G[100000];
int dist[100000];
bool used[100000];

void dijkstra(int v){
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(1, v));
    while(!que.empty()){
        P top = que.top();
        que.pop();
        int u = top.second;
        int d = top.first;
        //cout << u << ' ' << d << endl;
        if(used[u]) continue;
        dist[u] = d;
        used[u] = true;
        for(int i = 0; i < G[u].size(); i++){
            if(!used[G[u][i].to]){
                que.push(P(d+G[u][i].cost, G[u][i].to));
                //cout << G[u][i].to << ' ' <<  d+G[u][i].cost << endl;
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 1; i < N; i++){
        G[i].push_back(edge{(i+1)%N, 1});
        G[i].push_back(edge{(i*10)%N, 0});
    }
    dijkstra(1);
    cout << dist[0] << endl;
}