#include<bits/stdc++.h>
using namespace std;

int main(){
    int INF = 1'000'000'000;
    typedef pair<int, int> P;
    int k;
    cin >> k;
    vector<vector<P>> node(k);
    for (int i = 0; i < k; i++){
        node[i].push_back({(i+1)%k, 1});
        node[i].push_back({(i*10)%k, 0});
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> distance(k, INF);
    distance[1] = 0;

    pq.push({0, 1});
    while (pq.size() > 0){
        P p = pq.top(); pq.pop();
        //secondは行き先
        int v = p.second;
        //firstは距離
        if (distance[v] < p.first) continue;
        for (int i = 0; i < node[v].size(); i++){
            if (distance[node[v][i].first] > distance[v] + node[v][i].second){
                distance[node[v][i].first] = distance[v] + node[v][i].second;
                pq.push({distance[node[v][i].first], node[v][i].first});
            }
        }
    }

    cout << distance[0] + 1 << endl;
}