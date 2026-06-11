#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

vector<P> to[100005];
int ans [100005];

void dfs(int v, int p = -1) {
    for (auto e: to[v]) {
        if (e.first==p) continue;
        ans[e.first] = (ans[v] + e.second)%2;
        dfs(e.first, v);
    }
}

int main(){
    int n;
    cin >> n;
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        to[u].emplace_back(v, w);
        to[v].emplace_back(u, w);
    }
    dfs(0);
    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}
