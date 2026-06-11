#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int N;
vector<P> G[200005];
int height[200005];

void dfs(int v, int p, int h) {
    height[v] = h;
    for (auto uw : G[v]) {
        if (uw.first == p) continue;
        if (uw.second & 1) dfs(uw.first, v, 1 - h);
        else dfs(uw.first, v, h);
    }
}

int main() {
    cin >> N;
    rep(i,N-1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    dfs(0, -1, 1);
    rep(i,N) {
        cout << height[i] << endl;
    }
}