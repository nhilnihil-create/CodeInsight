#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0), C;
vector<vector<ll>> G;

void dfs(ll now, ll pre) {
    for(int i=0;i<G[now].size();i++) {
        if(G[now][i]==pre) continue;
        dfs(G[now][i], now);
    }
    A[now] = C.back();
    if(now!=0) ans += C.back();
    C.pop_back();
}

signed main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<N;i++) {
        ll cn;
        cin >> cn;
        C.push_back(cn);
    }
    sort(C.begin(), C.end(), greater<ll>());
    dfs(0,-1);
    cout << ans << endl;
    for(int i=0;i<N;i++) {
        cout << A[i] << endl;
    }
    return 0;
}