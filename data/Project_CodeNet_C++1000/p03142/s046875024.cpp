#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;
using Graph = vector<vector<int> >; // グラフ

int pos[100010];
int ans[100010];

void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order) {
    seen[v] = true;
    for (auto next : G[v]) {
        if (seen[next]) continue; // 既に訪問済みなら探索しない
        rec(next, G, seen, order);
    }
    order.push_back(v);
}

void dfs(int v, int p, vector<bool> &seen, const Graph &G){
    seen[v] = true;
    ans[v] = p;
    for(auto nv : G[v]){
        if (seen[nv]) continue;
        dfs(nv, v, seen, G);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    Graph g(n), rev(n), g2(n);

    rep(i, n+m-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<bool> seen(n, 0); // 初期状態では全ノードが未訪問
    vector<int> order; // トポロジカルソート順
    for (int v = 0; v < n; ++v) {
        if (seen[v]) continue; // 既に訪問済みなら探索しない
        rec(v, g, seen, order);
    }
    reverse(order.begin(), order.end()); // 逆順に

    rep(i, n) pos[order[i]] = i;

    int p;

    rep(i, n){
        if (rev[i].size() == 0){
            p = i;
            continue;
        }
        int tmp = 0;
        for(auto from : rev[i]){
            tmp = max(pos[from], tmp);
        }
        for(auto from : rev[i]){
            if (pos[from] == tmp){
                g2[from].push_back(i);
                break;
            }
        }
    }

    rep(i, n) seen[i] = 0;

    dfs(p, -1, seen, g2);

    rep(i, n) cout << ans[i] + 1 << endl;

    return 0;
}
