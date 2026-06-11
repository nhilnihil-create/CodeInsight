#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define NIL 0
#define INF 1e18
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define vl vector<ll>
#define vvl vector<vector<ll>> 
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define pb push_back
#define F first
#define S second
#define pp pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define rpk(i,k,n) for(int i=k;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++) 
#define RPK(i,k,n) for(int i=k;i<=n;i++) 
#define ritr(i,gr) for(auto i=gr.begin();i!=gr.end();i++)

const int M = 1e9+7;

int V, E, i, j, k, u, v, x, y, p, q, r;
vi *g;
vb sn;

void add_edge(int a,int b) { g[a].pb(b); g[b].pb(a);}

pp dfs_util( int s) {
    sn[s] = true;
    ll cb = 1, cw = 1;
    ritr(i, g[s]) {
        int to = *i;
        if(!sn[to]) {
            pp cnt = dfs_util(to);
            cb = (cb*(cnt.F%M))%M;
            cw = (cw*((cnt.F+cnt.S)%M))%M;
        }
    } 
    return mp(cw, cb);
}

void solve() {
    ll res = 0 ;
    sn.assign(V+1,false);
    pp cnt = dfs_util(1);
    res = (cnt.F+cnt.S)%M;
    cout<<res<<"\n";
}


int main() {
    cin>>V;
    E=V-1;
    g = new vi[V+1];
    rep(i,E) {
        cin>>x>>y;
        add_edge(x,y);
    }
    solve();
}
