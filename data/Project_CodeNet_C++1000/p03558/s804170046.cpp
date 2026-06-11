// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
const int INF = 1e15;

int n;
vector<pair<int, int> > adj[N];
int dist[N];

void dijkartas(int s) { 
    for(int i = 0; i < N; i++)
        dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; 
    
    pq.push({0, s}); 
    dist[s] = 0; 
    while(!pq.empty()) { 
        int v = pq.top().second; 
        pq.pop();
         
        for(auto p : adj[v]) { 
            int u = p.first; 
            int w = p.second; 
            if (dist[u] > dist[v] + w) { 
                dist[u] = dist[v] + w; 
                pq.push({dist[u], u}); 
            } 
        } 
    }  
} 
  
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t = 1; 
    // cin >> t; 
    while (t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            adj[(i % n)].push_back({(i + 1) % n, 1});
            adj[(i % n)].push_back({(10 * i) % n, 0});
        }
        
        dijkartas(1);
        cout << dist[0] + 1 << '\n';
    }
    
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

