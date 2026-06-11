#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "Yes" << endl; else cout << "No" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl; }}

struct edge{int to, cost;};

class Graph
{
public:
    int V;
    vector<vector<edge>> G;

    Graph(int V): V(V){
        G = vector<vector<edge>>(V, vector<edge>(0));
    }

    void add_edge(int from, int to, int cost){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

    //SCC decomposition
    void dfs(int v, vector<bool> &used, vec &vs){
        used[v] = true;
        REP(i, G[v].size()){
            if(!used[G[v][i].to]) dfs(G[v][i].to, used, vs);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k, vector<bool> &used, vec &cmp){
        used[v] = true;
        cmp[v] = k;
        REP(i, G[v].size()){
            if(!used[G[v][i].to]) rdfs(G[v][i].to, k, used, cmp);
        }
    }
    vec scc(int &k){
        vector<bool> used(V, false);
        vec vs(0), cmp(V);
        REP(i, V){
            if(!used[i]) dfs(i, used, vs); 
        }
        //reverse graph
        Graph rG(V);
        REP(v, V) REP(i, G[v].size()) rG.add_edge(G[v][i].to, v, G[v][i].cost);

        fill(used.begin(), used.end(), false);
        k = 0;
        IREP(i, vs.size()){
            if(!used[vs[i]]) rG.rdfs(vs[i], k++, used, cmp);
        }
        return cmp;
    }

};

signed main(){

    int N, M; cin >> N >> M;
    string s; cin >> s;
    int a, b;
    Graph G(2 * N);
    REP(i, M){
        cin >> a >> b;
        a--; b--;
        if(s[a] == s[b]){
            G.add_edge(a, b + N, 0);
            G.add_edge(b, a + N, 0);
        }else{
            G.add_edge(a + N, b, 0);
            G.add_edge(b + N, a, 0);
        }
    }
    int k;
    G.scc(k);
    ANS(k < 2 * N);
    
    return 0;
}