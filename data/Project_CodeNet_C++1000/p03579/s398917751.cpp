#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, M, ans=0, tmp=0;
vector<ll> color;
vector<vector<ll>> G;

bool bfs(ll id, ll state) {
    queue<ll> Q;
    color[id] = state;
    Q.push(id);
    while(!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++) {
            if(color[G[u][i]]==-1) {
                color[G[u][i]] = 1-color[u];
                Q.push(G[u][i]);
            }
            else {
                if(color[G[u][i]]==color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

signed main(){
    cin >> N >> M;
    G.resize(N);
    color.resize(N, -1);
    for(int i=0;i<M;i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(bfs(0, 0)) {
        for(int i=0;i<N;i++) {
            if(color[i]==1) tmp++;
        }
        ans = tmp*(N-tmp);
    }
    else ans = N*(N-1)/2;
    cout << ans-M << endl;
    return 0;
}