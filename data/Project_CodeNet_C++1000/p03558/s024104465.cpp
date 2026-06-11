#include <bits/stdc++.h>
using namespace std;

struct edge{
    int to,cost;
};

const int INF  = 10000000;

int k;

vector<edge> g[100001];

int d[100001];

void dijkstra(int s){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > que;
    fill(d,d+k,INF);
    d[s] = 0;
    que.push(make_pair(0,s));

    while(!que.empty()){
        pair<int,int> p = que.top(); que.pop();
        int dijkstra_tmp = p.second;
        if(d[dijkstra_tmp] < p.first){
            continue;
        }
        for(int i=0; i < g[dijkstra_tmp].size(); i++){
            edge e = g[dijkstra_tmp][i];
            if(d[e.to] > d[dijkstra_tmp] + e.cost){
                d[e.to] = d[dijkstra_tmp] + e.cost;
                que.push(make_pair(d[e.to],e.to));
            }
        }
    }
}

int main() {

    cin >> k;

    edge e;

    for(int i=0; i<k-1; i++){
        e.cost = 1;
        e.to = i+1;
        g[i].push_back(e);
        e.cost = 0;
        e.to = (i*10)%k;
        g[i].push_back(e);
    }

    e.cost = 1;
    e.to = 0;
    g[k-1].push_back(e);
    e.cost = 0;
    e.to = ((k-1)*10)%k;
    g[k-1].push_back(e);

    dijkstra(1);

    cout << d[0] + 1 << endl;

    return 0;
}