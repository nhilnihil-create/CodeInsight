#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int maxN = 1e5 + 10;
const int inf = 3e18 + 10;

typedef pair<int, int> ii;

int k;
int dist[maxN];
vector<ii> adj[maxN];

void dijkstra(int src){
    priority_queue<ii , vector<ii> , greater<ii> > pq ;

    for(int i = 0; i < maxN; ++i)
        dist[i] = inf;

    pq.push({0,src});
    dist[src] = 0 ;

    while(!pq.empty()){
        int u = pq.top().se;
        pq.pop();

        for(auto &t : adj[u]){
            int v = t.fi;
            int w = t.se;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w ;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[0] + 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(); cout.tie();

    cin >> k;

    for(int i = 1; i <= k; ++i){
        int u = i % k;
        int v = (i + 1) % k;
        adj[u].push_back({v,1});
    }

    for(int i = 1; i <= k; ++i){
        int u = i % k;
        int v = (10 * i) % k;
        adj[u].push_back({v,0});
    }

    dijkstra(1);
}
