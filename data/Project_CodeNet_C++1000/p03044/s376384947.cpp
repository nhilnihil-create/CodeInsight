#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

struct edge{
    ll to;
    ll cost;
};

void dfs(ll k,vector<ll> &color, vector<bool> &is_visited, vector<vector<edge>> &G){
    is_visited[k] = true;

    rep(i,0,G[k].size()){
        if(!is_visited[G[k][i].to]){
            if(G[k][i].cost % 2 == 0) color[G[k][i].to] = color[k];
            else color[G[k][i].to] = color[k] ^ 1;
            dfs(G[k][i].to, color, is_visited, G);
        }
    }

}

int main(){
    ll n;
    cin >> n;
    vector<bool> is_visited(n, false);
    vector<ll> color(n);

    vector<vector<edge>> G(n);
    rep(i,0,n-1){
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        edge e; e.cost = w; e.to = v;
        G[u].push_back(e);
        e.to = u;
        G[v].push_back(e);
    }

    color[0] = 0;
    dfs(0,color,is_visited,G);

    rep(i,0,n){
        cout << color[i] << endl;
    }
    return 0;
}
