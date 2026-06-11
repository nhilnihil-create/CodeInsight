#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll n, m;
    cin >> n >> m;    
    
    vvl G(n-1+m);  // 辺の重みがすべて1のグラフ
    vl indeg(n);  // indeg[v] : 頂点vの入次数
    rep(i, n-1+m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        indeg[b]++;
    }
    
    // BFS。計算量はO(V+E)
    queue<ll> Q;
    vl ans(n);  // ans[v] : 頂点vの親の頂点番号
    rep(v, n) {
        if(indeg[v] == 0) {
            ans[v] = -1;
            Q.push(v);
        }
    }
    
    while(!Q.empty()) {
        ll v = Q.front();
        Q.pop();
        for(auto u : G[v]) {
            indeg[u]--;
            if(indeg[u] == 0) {
                ans[u] = v;
                Q.push(u);
            }
        }
    }

    rep(v, n) {
        out(ans[v] + 1);
    }
    
    re0;
}