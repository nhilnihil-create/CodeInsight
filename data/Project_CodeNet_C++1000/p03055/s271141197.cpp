#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

template <typename T>
vector<T> Dijkstra(int s, vector<vector<pair<int, T>>> & G, /*vector<int> & prev,*/ const T INF = 1e9){
    using P = pair<T, int>;
    int V = G.size();
    vector<T> dist(V, INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(0, s);
    /*prev.assign(V, -1);*/
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        for(int i = 0; i < G[v].size(); i++){
            int to = G[v][i].first;
            T cost = G[v][i].second;
            if(dist[to] > dist[v] + cost){
                dist[to] = dist[v] + cost;
                /*prev[to] = v;*/
                que.emplace(dist[to], to);
            }
        }
    }
    return dist;
}

signed main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "First" << endl;
        return 0;
    }
    vector<vector<pair<int, int>>> G(n);
    int a,b;
    rep(i,n - 1){
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b, 1);
        G[b].emplace_back(a, 1);
    }
    vector<int> dist = Dijkstra(0, G);
    int v;
    int mx = 0;
    rep(i,n){
        if(dist[i] > mx){
            mx = dist[i];
            v = i;
        }
    }
    vector<int> distv = Dijkstra(v, G);
    int d = 0;
    rep(i,n){
        d = max(d, distv[i]);
    }
    cout << (d % 3 == 1 ? "Second" : "First") << endl;
    return 0;
}