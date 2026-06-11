#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define int long long
#define all(a) a.begin(), a.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

int n, m;
struct edge{
   int to, cost;
};
vector<edge> G[100010];
int dist[100010];

void dfs(int now, int pre){
    rep(i, 0, G[now].size()){
        int nxt = G[now][i].to;
        if(nxt == pre) continue;
        if(dist[nxt] != INF) continue;
        int cost = dist[now] + G[now][i].cost;
        dist[nxt] = cost;
        dfs(nxt, now);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> l(m), r(m), d(m);
    rep(i, 0, m){
        cin >> l[i] >> r[i] >> d[i];
        l[i]--; r[i]--;
        G[l[i]].push_back({r[i], d[i]});
        G[r[i]].push_back({l[i], -d[i]});
    }
    rep(i, 0, n) dist[i] = INF;
    rep(i, 0, n){
        if(dist[i] != INF) continue;
        dist[i] = 0;
        dfs(i, -1);
    }
    bool ans = true;
    rep(i, 0, m){
        if(dist[r[i]] - dist[l[i]] != d[i]) ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}