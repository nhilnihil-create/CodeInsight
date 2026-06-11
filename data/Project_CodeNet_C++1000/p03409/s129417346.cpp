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



struct Biparite_Matching {

    int n;
    vector<vector<int>> g;
    vector<int> match;
    vector<bool> seen;

    Biparite_Matching(int _n) {
        n = _n;
        g.assign(n, vector<int>());
        match.resize(n);
        seen.resize(n);
    }

    // 辺の追加
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(int v) {
        seen[v] = true;
        for(int i = 0; i < (int)g[v].size(); i++) {
            int u = g[v][i];
            int w = match[u];
            if(w < 0 || (!seen[w] && dfs(w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    // 最大マッチング
    int count() {
        int res = 0;
        match.assign(n, -1);
        for(int v = 0; v < n; v++) {
            if(match[v] < 0) {
                seen.assign(n, false);
                if(dfs(v)) res++;
            }
        }
        return res;
    }

};


int main(){

    int n;
    cin >> n;
    V<P> as(n), bs(n);
    rep(i,n) cin >> as[i].fi >> as[i].se;
    rep(i,n) cin >> bs[i].fi >> bs[i].se;

    Biparite_Matching bm(n*2);
    rep(i,n)rep(j,n) {
        if(as[i].fi < bs[j].fi && as[i].se < bs[j].se) 
            bm.add_edge(i, j+n);
    }

    int ans = bm.count();
    cout << ans << endl;
}