#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a, Ts... ts) {return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }

template<typename T,typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v){ t = v; }

template<typename T,typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v){ for(auto &e : t) fill_v(e, v); }

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

class BipartiteGraph {
    private:
        vector<vector<int>> graph;
        int V; // 頂点数
        bool Dfs(int v, int color);

    public:
        vector<int> color; // 頂点iの色(1 or -1)
        BipartiteGraph(int n);
        void AddEdge(int f, int t);
        bool Run(); // 2部グラフか否か
};

BipartiteGraph::BipartiteGraph(int n):
    graph(vector<vector<int>>(n)),
    V(n),
    color(vector<int>(n))
{}

void BipartiteGraph::AddEdge(int f, int t){
    graph[f].push_back(t);
}

bool BipartiteGraph::Dfs(int v, int c){
    color[v] = c;
    for(auto x: graph[v]){
        if(color[x] == c) return false;
        if(color[x] == 0 && !Dfs(x, -c)) return false;
    }

    return true;
}

bool BipartiteGraph::Run(){
    for(int i = 0; i < V; i++){
        if(color[i] == 0){
            if(!Dfs(i, 1)){
                return false;
            }
        }
    }
    return true;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    
    BipartiteGraph bg(n);
    REP(i, m)
    {
        int a, b; 
        cin >> a >> b;
        a--, b--;
        bg.AddEdge(a, b);
        bg.AddEdge(b, a);
    }

    if(bg.Run())
    {
        int b = 0, w = 0;
        REP(i, n) (bg.color[i] == 1 ? b : w)++;
        cout << b*w - m << endl;
    }
    else 
    {
        cout << n*(n-1)/2 - m << endl;
    }
}