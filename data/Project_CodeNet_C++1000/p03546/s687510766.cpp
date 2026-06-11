#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const int INF = 1e9;
int c[10][10], d[10];

void dijkstra(int s){
    vector<bool> visited(10);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, s);
    d[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        int v = -pq.top().first;
        pq.pop();
        visited[u] = true;
        if(v > d[u]) continue;
        for(int i = 0; i < 10; i++){
            if(visited[i]) continue;
            if(d[i] > d[u] + c[i][u]){
                d[i] = d[u] + c[i][u];
                pq.emplace(-d[i], i);
            }
        }
    }
}

int main(){
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < 10; i++){
        d[i] = INF;
        for(int j = 0; j < 10; j++){
            cin >> c[i][j];
        }
    }
    dijkstra(1);
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int a;
            cin >> a;
            if(a == -1) continue;
            ans += d[a];
        }
    }
    cout << ans << endl;
    return 0;
}