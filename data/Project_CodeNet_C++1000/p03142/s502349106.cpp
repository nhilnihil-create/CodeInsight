#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, M, tmp=0;
vector<ll> A, indeg, ans;
vector<vector<ll>> G;

void bfs(ll st) {
    queue<ll> Q;
    Q.push(st);
    while(!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++) {
            indeg[G[u][i]]--;
            if(indeg[G[u][i]]==0) {
                Q.push(G[u][i]);
                ans[G[u][i]] = u;
            }
        }
    }
}

signed main() {
    cin >> N >> M;
    indeg.resize(N);
    ans.resize(N);
    G.resize(N);
    for(int i=0;i<N;i++) {
        indeg[i] = 0;
    }
    for(int i=0;i<N+M-1;i++) {
        ll a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        indeg[b-1]++;
    }
    for(int i=0;i<N;i++) {
        if(indeg[i]==0) {
            bfs(i);
            ans[i] = -1;
            break;
        }
    }
    for(int i=0;i<N;i++) {
        cout << ans[i]+1 << endl;
    }
    return 0;
}