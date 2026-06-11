#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

struct topological_sort{
    vector<vector<int>> G;
    vector<int> indegree;
    vector<int> par;
    int V;

    topological_sort(int V) : V(V) {G.resize(V); indegree.resize(V); par.assign(V,-1);}
    void add_edge(int a, int b) {
        G[a].push_back(b);
        indegree[b]++;
    }
    void sort() {
        queue<int> q;
        for (int i = 0; i < V; i++) if (indegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < G[v].size(); i++) {
                int u = G[v][i];
                par[u] = v + 1;
                indegree[u]--;
                if (indegree[u] == 0) q.push(u);
            }
        }
    }
};

int main() {
    int n, m; cin >> n >> m;
    topological_sort ts(n);
    vvint dest(n);
    rep(i,n-1+m) {
        int a, b; cin >> a >> b;
        a--; b--;
        ts.add_edge(a,b);
        dest[b].push_back(a);
    }
    ts.sort();
    vint ans = ts.par;
    rep(i,ans.size()) {
        cout << (ans[i] == -1 ? 0 : ans[i]) << endl;
    }
}