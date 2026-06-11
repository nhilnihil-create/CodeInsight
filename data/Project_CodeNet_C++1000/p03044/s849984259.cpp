#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long
#define MAX_N 100001

using namespace std;

long long MOD = 1000000007;

struct edge
{
    ll cost;
    int to;
};


void dfs(int x, ll cost, vector<vector<edge>> &edges, vector<ll> &dist){
    if(dist[x]!=MOD*MOD){
        return;
    }
    dist[x]=cost;
    for(auto &e:edges[x]){
        dfs(e.to,cost+e.cost,edges,dist);
    }
}

int main(){
    int N;
    cin >> N;

    vector<vector<edge>> edges(N,vector<edge>(0));
    for(int i=0; i<N-1; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        edges[u].push_back({w,v});
        edges[v].push_back({w,u});
    }

    vector<ll> dist(N,MOD*MOD);
    dfs(0,0,edges,dist);
    for(int i=0; i<N; i++){
        if(dist[i]%2==0){
            cout << 0 << '\n';
        }else{
            cout << 1 << '\n';
        }
    }
}