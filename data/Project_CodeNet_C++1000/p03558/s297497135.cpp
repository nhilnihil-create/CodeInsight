#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e12;

// computational complexity : O(E*logV)

struct edge{
    int to, cost;
};

int V,E;// number of (vertices, edges)
vector<vector<edge>> graph;
vector<long long int> d;// shortest distances

void Dijkstra(int s){// s = starting point
    priority_queue<
        pair<int, int>// temporarily keeping (shortest distance, vertex)
        , vector<pair<int, int>>, greater<pair<int, int>>// shorter ones first
    > pq;

    // initialize (INF)
    for(int i=0; i<V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    pq.push({0,s});

    // search
    pair<int, int> current;// (shortest-distance confirmed, vertex)
    while(!pq.empty()){
        current = pq.top(); pq.pop();

        int v = current.second;
        if(d[v] < current.first){
            continue;// ignore (not the shortest path)
        }
        // else (need to check)
        for(edge e : graph[v]){// adjacent nodes
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;// update minimum cost
                pq.push({d[e.to], e.to});
            }
        }
    }
}

int main(){
    int k;
    cin >> k;

    V = k;
    graph.resize(V);
    d.resize(V);

    for(int i=0; i<k; i++){
        graph[i].push_back({(i+1)%k, 1});
        graph[i].push_back({(10*i)%k, 0});
    }

    Dijkstra(1);
    cout << d[0] + 1 << endl;
    return 0;
}