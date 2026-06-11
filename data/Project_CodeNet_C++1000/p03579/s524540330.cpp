#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
struct Node{
    int id;
    T v;
    bool done = false;
    Node(int id, T v=1e9): id(id), v(v) {}
    Node(): id(0), v(1e9) {}
};

template<typename T>
struct Edge{
    int from, to, id;
    T cost;
    Edge(int from, int to, T cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}
};

template<typename T>
struct Graph{
    int N;
    vector<vector<Edge<T>>> adj;
    vector<Node<T>> node;

    Graph(int N): N(N) {
        adj.resize(N);
        node.resize(N);
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, T cost=1, int id=-1){
        Edge<T> e(i, j, cost, id);
        adj[i].emplace_back(e);
    }

    vector<Edge<T>> get_adj(Node<T> node){
        return adj[node.id];
    }

    void resize(int n){
        N = n;
        adj.resize(N);
        node.resize(N);
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void init(T cost=1e9){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = cost;
        }
    }
};

VI colors;
Graph<int> G;

bool dfs(int v, int color){
    colors[v] = color;

    for(auto& e : G.adj[v]){
        if(colors[e.to] == color) return false;
        if(colors[e.to] == -1 && !dfs(e.to, color^1)) return false;
    }

    return true;
}

bool is_bipartite(){
    return dfs(0,1);
}


void Main(){
    ll N,M; cin >> N >> M; G.resize(N); colors.resize(N,-1);
    REP(i,M){
        int a,b; cin >> a >> b; a--; b--;
        G.add_edge(a,b); G.add_edge(b,a);
    }

    ll ans;
    if(is_bipartite()){
        ll B = 0, W = 0;
        REP(i,N) if(colors[i] == 0) B++; else W++;
        ans = B*W-M;
    }
    else{
        ans = N*(N-1)/2 - M;
    }
    cout << ans << en;
    return;
}

int main(void){
    cin.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t){
        Main();
    }
    return 0;
}