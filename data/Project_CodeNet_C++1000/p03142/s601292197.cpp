#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using Graph = vector<vector<int>>;
int cnt[100010];
int par[100010];

int main() {
    int n, m; cin >> n >> m;
    Graph g(n);
    rep(i, n+m-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        cnt[b]++;
    }

    int root = -1;
    rep(i, n) if (cnt[i] == 0) root = i;

    // BFSして最長距離のedgeだけ残す
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: g[u]) {
            cnt[v]--;
            if (cnt[v] > 0) continue;
            par[v] = u;
            q.push(v);
        }
    }

    rep(i, n) {
        if (i == root) cout << 0 << endl;
        else cout << par[i] + 1 << endl;
    }
}
