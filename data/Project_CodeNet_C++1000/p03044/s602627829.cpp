#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

struct edge{
    int to;
    int cost;
};

vector<int> colors;
vector<vector<edge>> edges;

void dfs(int vertex, int color, int parent=-1){
    colors[vertex] = color;

    for (auto e : edges[vertex]){
        if (e.to == parent) continue;
        int next_color = color;
        if (e.cost == 1) next_color = 1 - color;
        dfs(e.to, next_color, vertex);
    }

}

int main(){

    int N; cin >> N;
    colors.assign(N,0);
    edges.assign(N, vector<edge>());
    rep(i,N-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        w = w % 2;
        edges[u].push_back(edge{v,w});
        edges[v].push_back(edge{u,w});
        //edges[u].emplace_back(v,w);
        //edges[v].emplace_back(u,w);
    }

    dfs(0,0);

    rep(i,N){
        cout << colors[i] << endl;
    }

}