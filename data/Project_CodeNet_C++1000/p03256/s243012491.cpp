#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;
 
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;
 
template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);
 
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
 
    void erase_edge(int from, int to){
        vec e(0);
        REP(i, G[from].size()){
            if(G[from][i].to == to) e.push_back(i);
        }
        IREP(i, e.size()) G[from].erase(G[from].begin() + e[i]);
    }
 
    void erase_edge2(int v1, int v2){
        erase_edge(v1, v2);
        erase_edge(v2, v1);
    }

    bool dfs(int v, vector<bool> &tmp_used, vector<bool> &used){
        REP(k, G[v].size()){
            if(tmp_used[G[v][k].to]) return true;
            tmp_used[G[v][k].to] = true;
            used[G[v][k].to] = true;
            if(dfs(G[v][k].to, tmp_used, used)) return true;
            tmp_used[G[v][k].to] = false;
        }
        return false;
    }
};
 
 
 
signed main(){
 
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    vec ab(N);
    REP(i, N){
        if(s[i] == 'A'){
            ab[i] = 1;
        }else{
            ab[i] = 0;
        }
    }
    Graph G(2 * N);
    vec a(M), b(M);
    REP(i, M){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if(ab[a[i]] == ab[b[i]]){
            G.add_edge(a[i], b[i] + N, 0);
            G.add_edge(b[i], a[i] + N, 0);
        }else{
            G.add_edge(a[i] + N, b[i], 0);
            G.add_edge(b[i] + N, a[i], 0);
        }
    }
 
    bool ans = false;
    vector<bool> tmp_used(2 * N, false), used(2 * N, false);
    REP(i, 2 * N){
        if(used[i]) continue;
        used[i] = true;
        tmp_used[i] = true;
        if(G.dfs(i, tmp_used, used)) ans = true;
        tmp_used[i] = false;
    }


    if(ans){
        cout << "Yes";
    }else{
        cout << "No";
    }
    
    return 0;
}
 
 
template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}