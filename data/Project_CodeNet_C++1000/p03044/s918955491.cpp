#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0);
vector<vector<pair<ll,ll>>> G;

void dfs(ll now, ll pre, ll c) {
    A[now] = c;
    for(int i=0;i<G[now].size();i++) {
        if(G[now][i].first==pre) continue;
        else {
            if(G[now][i].second%2==1) dfs(G[now][i].first,now,1-c);
            else dfs(G[now][i].first,now,c);
        }
    }
}

signed main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    dfs(0,-1, 0);
    for(int i=0;i<N;i++) {
        cout << A[i] << endl;
    }
    return 0;
}