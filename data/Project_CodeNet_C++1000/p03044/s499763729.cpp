#include <bits/stdc++.h>

#define irep(i,n) for(int i = 0; i < (int)(n); i++)
#define irep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define irrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define irrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

#define fi first
#define se second

using namespace std;

using ll = long long;
using v_int = vector<int>;
using v2_int = vector<v_int>;
using v_ll = vector<ll>;
using v2_ll = vector<v_ll>;
using v_string = vector<string>;
using v_bool = vector<bool>;
using v2_bool = vector<v_bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

const double PI = 3.1415926535897932;
const int INF = (int)2e9;
const ll LINF = (ll)2e18;
const ll MOD = 1000000007;
const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p) {
    return o << "{" << p.first << "," << p.second << "}";
}
template<typename T> inline
istream& operator>>(istream &is, vector<T> &vec) {
    for(auto &v : vec) { is >> v; }
    return is;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &vec) {
    for(auto &v : vec) { os << v << ",";}
    return os;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<vector<T> > &mat) {
    for(auto &row : mat) { os << row << endl; }
    return os;
}
template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }
template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

struct Edge {
    int cost, to;
    Edge(int to_, int cost_) : 
        to(to_), cost(cost_) { } 
};

using Graph = vector<vector<Edge> >;

Graph graph;
v_int ans;

void solve(int from, ll d)
{
    for(auto node : graph[from]) {
        if(ans[node.to] != INF) { continue; }    
        if((d + node.cost)%2 == 0) {
            ans[node.to] = 1;    
        } else {
            ans[node.to] = 0;
        }
        solve(node.to, d+node.cost);
    }
}

int main(void)
{
    int n;
    cin >> n;
    
    graph.resize(n);
    ans.assign(n, INF);

    irep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back(Edge(v-1, w));
        graph[v-1].push_back(Edge(u-1, w));
    }

    ll d = 0;
    ans[0] = 1;

    solve(0, d);

    irep(i, n) {
        cout << ans[i] << endl;
    }
    
    return 0;
} /*atcoder*/
