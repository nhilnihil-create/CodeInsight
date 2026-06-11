#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct Node{
    int id;
    int v;
    bool done = false;
    Node(int id, int v=1e9): id(id), v(v) {}
    Node(): id(0), v(1e9) {}
};

bool operator>(Node a, Node  b){
    return a.v > b.v;
}

struct Edge{
    int from, to, id;
    int cost;
    Edge(int from, int to, int cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}
};

struct Graph{
    int N;
    vector<vector<Edge>> adj;
    vector<Node> node;

    Graph(int N): N(N) {
        adj.assign(N, vector<Edge>());
        node.assign(N, Node());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    Graph() {}

    void add_edge(int i, int j, int cost=1, int id=-1){
        Edge e(i, j, cost, id);
        adj[i].emplace_back(e);
    }

    vector<Edge> get_adj(Node node){
        return adj[node.id];
    }

    void assign(int n){
        N = n;
        adj.assign(N, vector<Edge>());
        node.assign(N, Node());
        for(int i=0; i<N; ++i) node[i].id = i;
    }

    void reset(){
        for(int i=0; i<N; ++i){
            node[i].done = false;
            node[i].v = 1e9;
        }
    }
};

Graph G;
int N,M;
VI dp;

int dfs(int n){
    if(dp[n] != -1) return dp[n];
    int res = 0;
    for(Edge e : G.adj[n]){
        chmax(res, dfs(e.to)+1);
    }
    return dp[n] = res;
}

int main(void){
    cin >> N >> M;
    G.assign(N); dp.assign(N,-1);
    REP(i,N+M-1){
        int a,b; cin >> a >> b; a--; b--;
        G.add_edge(b,a);
    }

    VI ans(N,0);
    REP(i,N){
        for(Edge e : G.adj[i]){
            if(dfs(i) == dfs(e.to)+1) ans[i] = e.to+1;
        }
    }

    REP(i,N) cout << ans[i] << en;
    return 0;
}