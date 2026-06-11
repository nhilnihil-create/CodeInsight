#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

// graph template
template<typename T>
class Edge{
    public:
        int src, to; T cost;

        Edge(int to, T cost): src(-1), to(to), cost(cost){}
        Edge(int src, int to, T cost): src(src), to(to), cost(cost){}
};
template<typename T>
using Edges = vector<Edge<T>>;
template<typename T>
using AdjacencyList = vector<Edges<T>>;
template<typename T>
using Matrix = vector<vector<T>>;

vector<int> color(100000, -1);
vector<vector<int>> G(100000);

bool dfs(int v){
    for(int next: G[v]){
        if(color[v] == color[next]){
            return false;
        }else if(color[v] == (color[next]^1)){
            continue;
        }else if(color[next] == -1){
            color[next] = (color[v]^1);
            if(dfs(next) == false) return false;
        }
    }
    return true;
}

int main(void){
    int N, M;
    cin >> N >> M;
    
    Edges<int> es;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        es.emplace_back(Edge<int>(a, b, 1));
    }

    ll res = 0;
    color[0] = 0;
    if(dfs(0)){
        ll b = 0, w = 0;
        for(int i = 0; i < N; i++){
            if(color[i] == 0) w++;
            else if(color[i] == 1) b++;
        }
        res = w * b;
        res -= M;
      }else{
        res = (ll)N * (N - 1) / 2;
        res -= M;
    }

    cout << res << '\n';

    return 0;
}