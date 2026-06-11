#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

struct Ford_Fulkerson {

    // 行先、容量、逆辺の行先の g での index;
    struct edge { int to, cap, rev; };

    int n;
    vector<vector<edge>> g;
    vector<bool> seen;

    Ford_Fulkerson(int _n) {
        n = _n;
        g.assign(n, vector<edge>());
        seen.assign(n, false);
    }

    // 辺の追加
    void add_edge(int from, int to, int cost) {
        g[from].push_back(edge{to, cost, (int)g[to].size()});
        g[to].push_back(edge{from, 0, (int)g[from].size() - 1});
    }

    // v から t へのパスを探して最大流量を返す
    int dfs(int v, int t, int mincap) {
        if(v == t) return mincap;
        seen[v] = true;
        for(edge &e : g[v]) {
            if(!seen[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(mincap, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // s から t への最大流
    int max_flow(int s, int t) {
        int flow = 0;
        for(;;) {
            seen.assign(seen.size(), false);
            int f = dfs(s, t, inf);
            if(f == 0) return flow;
            flow += f;
        }
    }

};

int main(){

    int n;
    cin >> n;
    V<P> rs(n), bs(n);

    rep(i,n) {
        int a, b;
        cin >> a >> b;
        rs[i] = make_pair(a,b);
    }
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        bs[i] = make_pair(a,b);
    }

    Ford_Fulkerson ff(n*2+2);
    rep(i,n)rep(j,n) {
        if(rs[i].fi < bs[j].fi && rs[i].se < bs[j].se) {
            ff.add_edge(i, j+n, 1);
        }
    }

    int l = n*2, r = n*2+1;
    rep(i,n) ff.add_edge(l,i,1);
    rep(i,n) ff.add_edge(i+n, r, 1);

    int ans = ff.max_flow(l,r);
    cout << ans << endl;
}