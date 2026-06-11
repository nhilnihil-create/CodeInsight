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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

struct Node{
    int id, v;
    bool done = false;
    Node(int id, int v=0): id(id), v(v) {}
    Node(): id(0), v(0) {}

    bool operator==(const Node& x) { return v == x.v; }
    bool operator!=(const Node& x) { return v != x.v; }
    bool operator<(const Node& x) { return v < x.v; }
    bool operator>(const Node& x) { return v > x.v; }
    bool operator<=(const Node& x) { return v <= x.v; }
    bool operator>=(const Node& x) { return v >= x.v; }

    bool comp(Node node){
        return v < node.v;
    }
};

struct Edge{
    int from, to, cost, id;
    Edge(int from, int to, int cost=1, int id=-1): from(from), to(to), cost(cost), id(id) {}

    bool comp(Edge e){
        return cost < e.cost;
    }
};

struct Graph{
    int N;
    vector<vector<Edge>> adj;
    vector<Node> node;

    Graph(int N): N(N) {
        adj.resize(N, vector<Edge>());
        node.resize(N);
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
};

int main(void){
    int N; cin >> N;
    Graph G(N);
    REP(i,N-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G.add_edge(a,b,1,i);
        G.add_edge(b,a,1,i);
    }
    VI c(N); REP(i,N) cin >> c[i];
    SORT(c);
    int ans = 0;
    REP(i,N-1) ans += c[i];
    queue<int> q;
    q.push(0);
    while(q.size()){
        int node = q.front(); q.pop();
        if(G.node[node].done) continue;
        G.node[node].done = true;
        G.node[node].v = c.back(); c.pop_back();
        for(Edge e : G.adj[node]){
            q.push(e.to);
        }
    }

    cout << ans << endl;
    REP(i,N) cout << G.node[i].v << " ";
    cout << endl;
    return 0;
}