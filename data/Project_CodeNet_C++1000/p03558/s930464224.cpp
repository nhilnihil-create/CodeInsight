#include<bits/stdc++.h>

using namespace std;

int main(void){
    int K;
    cin >> K;
    vector<int> dist(K, -1);

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[1] = 0;
    q.push(make_pair(dist[1], 1));
    while(!q.empty()){
        auto p = q.top(); q.pop();
        int x = p.second;
        int d = p.first;
        if(dist[x] != -1 && dist[x] < d) continue;
        if(dist[x*10%K] == -1 || dist[x*10%K] > dist[x] + 0){
            dist[x*10%K] = dist[x] + 0;
            q.push(make_pair(dist[x*10%K], x*10%K));
        }
        if(dist[(x+1)%K] == -1 || dist[(x+1)%K] > dist[x] + 1){
            dist[(x+1)%K] = dist[x] + 1;
            q.push(make_pair(dist[(x+1)%K], (x+1)%K));
        }
    }

    cout << dist[0] + 1 << endl;

    return 0;
}