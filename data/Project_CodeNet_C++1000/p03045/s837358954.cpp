#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, M, ans=0, tmp=0;
vector<ll> X(MAXN, 0), Y(MAXN, 0), Z(MAXN, 0), color;
vector<vector<ll>> G;

void bfs(ll start) {    
    queue<ll> Q;
    Q.push(start);
    color[start]=1;
    while(!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++) {
            if(color[G[u][i]]==1) continue;
            else {
                Q.push(G[u][i]);
                color[G[u][i]]=1;
                ans--;
            }
        }
    }
}

signed main(){
    cin >> N >> M;
    G.resize(N);
    color.resize(N);
    for(int i=0;i<N;i++) color[i]=0;
    for(int i=0;i<M;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = N;
    for(int i=0;i<N;i++) {
        if(color[i]==0) bfs(i);
    }
    cout << ans << endl;
    return 0;
}