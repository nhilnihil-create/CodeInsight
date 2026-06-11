#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int daijkstra(const vector<vector<pair<int,int>>> graph, int s, int t){
    vi dist(graph.size(),1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
    dist[s]=0;
    que.push({0,s});
    while(!que.empty()){
        auto v=que.top(); que.pop();
        if(v.first>dist[v.second]) continue;
        for(auto x:graph[v.second]){
            if(dist[x.second]>dist[v.second]+x.first){
                dist[x.second]=dist[v.second]+x.first;
                que.push({dist[x.second],x.second});
            }
        }
    }
    return dist[t];
}

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<pair<int,int>>> graph(10);
    rep(i,10){
        rep(j,10){
            int a;
            cin >> a;
            graph[i].push_back({a,j});
        }
    }

    vi cost(10);
    rep(i,10){
        cost[i]=daijkstra(graph,i,1);
    }
    int ans=0;
    rep(i,h){
        rep(j,w){
            int a;
            cin >> a;
            if(a==-1) continue;
            ans+=cost[a];
        }
    }
    cout << ans << endl;
}