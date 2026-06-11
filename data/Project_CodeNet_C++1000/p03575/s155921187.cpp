#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)(n-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

template<typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p){
    return o << "(" << p.first << ", " << p.second << ")";
}

struct UnionFind {
    int n;
    vector<int> dat;
    UnionFind(int size): n(size), dat(size, -1) { }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (dat[y] < dat[x]) swap(x, y);
            dat[x] += dat[y];
            dat[y] = x;
        }
        return x != y;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return dat[x] < 0 ? x : dat[x] = root(dat[x]);
    }
    int size(int x){
        return -dat[root(x)];
    }
};

void solve1(){
    int n,m; cin >> n >> m;
    vector<pii> es;
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        es.emplace_back(a, b);
    }

    int ans = 0;
    rep(i,m){
        auto uf = UnionFind(n);
        rep(j,m){
            if(i != j) uf.unite(es[j].fi, es[j].se);
        }
        if(!uf.same(es[i].fi, es[i].se)) ans++;
    }
    cout << ans << endl;
};

struct Lowlink{
    int n;
    vvi &g;
    vi used, ord, low;
    vi articulation;
    vector<pii> bridge;
    Lowlink(vvi &g): g(g){
        n = g.size();
        used = vi(n, 0);
        ord = vi(n, 0);
        low = vi(n, 0);
        int k = 0;
        rep(i,n){
            if(!used[i]) k = dfs(i, k, -1);
        }
    }
    int dfs(int v, int k, int par){
        used[v] = true;
        ord[v] = k++;
        low[v] = ord[v];
        bool is_articulation = false;
        int cnt = 0;
        for(auto u : g[v]){
            if(!used[u]){
                cnt++;
                k = dfs(u, k, v);
                is_articulation |= ~par && low[u] >= ord[v];
                low[v] = min(low[v], low[u]);
                if(ord[v] < low[u]) bridge.emplace_back(v, u);
            }else if(u != par){
                low[v] = min(low[v], ord[u]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if(is_articulation) articulation.push_back(v);
        return k;
    }
};

void solve2(){
    int n,m; cin >> n >> m;
    vvi g(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto lowlink = Lowlink(g);
    cout << lowlink.bridge.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    solve2();
    return 0;
}