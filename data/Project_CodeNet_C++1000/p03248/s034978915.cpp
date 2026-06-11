#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define SUM(a) accumulate(all(a), 0LL)
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define FOR(i, m, n) for(int (i)=(m); (i)<(n); i++)
#define FORR(i, m, n) for(int (i)=(n)-1; (i)>=(m); i--)
#define debug(x) cerr << #x << " = " << x << endl
//#define int long long

typedef long long ll;
//ll const MOD = 998244353;
ll const MOD = 1e9+7;
int const inf = 1e9;
ll const INF = 1e18;

inline void ios_(){cin.tie(0); ios::sync_with_stdio(false);}
template<typename T> int size(const T& a){return (int)a.size();}
template<typename T> T Div(T a, T b){return (a + b - 1) / b;}
template<typename T> bool chmin(T& a, const T& b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, const T& b){if(a < b){a = b; return true;} return false;}

#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using ll = long long;

struct Graph {
    struct Edge {
        int from;
        int to;
        ll cost;
        Edge(int a, ll b) : to(a), cost(b) {}
        Edge(int a, int b, ll c) : from(a), to(b), cost(c) {}
    };

    int N;  //頂点数
    std::vector<std::vector<Edge>> edges;   //隣接リスト
    std::vector<ll> dist;   //ノードの深さ
    std::vector<int> deg;   //入次数

    Graph(int n) : N(n), edges(n), dist(n, INF), deg(n, 0) {}

    void connect(int a, int b, ll c) {   //辺を追加
        edges[a].emplace_back(Edge(a, b, c));
        deg[b]++;
    }

    bool visited(int v) {
        return dist[v] < INF;
    }

    void resetDist() {
        for(int i=0; i<N; i++) {
            dist[i] = INF;
        }
    }

    void dfs(int p, int v, ll d) {    //深さ優先探索
        if(visited(v)) return;

        dist[v] = d;

        for(const Edge& e : edges[v]) {
            if(e.to == p) continue;
            dfs(v, e.to, d + e.cost);
        }
    }

    int makeStar(int n) {
        static int id = 0;
        int root = id;
        id++;
        for (int i = 0; i < n - 1; i++) {
            int next = makeStar(1);
            connect(root, next, 1);
            connect(next, root, 1);
        }
        return root;
    }

    int makeTree(int n, const vector<int>& v) {
        if(v[n] == 1) {
            return makeStar(1);
        }
        int x = makeTree(n+1, v);
        int y = makeStar(v[n] - v[n+1]);
        connect(x, y, 1);
        connect(y, x, 1);
        return y;
    }
};

void ng() {
    cout << -1 << endl;
    exit(0);
}

signed main(){
    string s;
    cin >> s;
    int n = s.length();

    if(s.front() == '0' || s.back() == '1'){
        ng();
    }

    vector<int> v{n};

    RREP(i, n/2){
        int a = i + 1, b = n - a;
        if(s[a-1] != s[b-1]) ng();
        if(s[a-1] == '1') v.push_back(a);
    }

    Graph G(n);
    G.makeTree(0, v);

    REP(i, n){
        for(const auto& e : G.edges[i]){
            if(e.from > e.to) continue;
            cout << e.from + 1 << " " << e.to + 1 << '\n';
        }
    }

    return 0;
}
