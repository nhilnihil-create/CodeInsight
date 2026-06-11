#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

struct edge{ll to, cost;};
vector<vector<edge>> G(100005);

vector<bool> ans(100005);

void dfs(ll v, ll p, bool c){
    ans[v] = c;

    rep(i, G[v].size()){
        if(G[v][i].to == p)continue;

        // 距離が奇数なので違う色で塗る
        if(G[v][i].cost & 1)dfs(G[v][i].to, v, !c);
        else dfs(G[v][i].to, v, c);
    }
}

int main(){
    ll n;
    cin >> n;

    rep(i, n-1){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        G[u].push_back(edge{v, w});
        G[v].push_back(edge{u, w});
    }

    dfs(0, 0, true);

    rep(i, n)cout << ans[i] << endl;
}