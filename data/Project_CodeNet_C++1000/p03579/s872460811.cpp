#include <iostream>
#include <cstdio>
#include <string>
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

vvl G;
vl color;  // color[v] : 0は白、1は黒、-1は未訪問

bool dfs(ll v, ll now = 0) {
    color[v] = now;
    for(auto u : G[v]) { 
        if(color[u] != -1) {
            if(color[u] == now) {
                return false;
            }
            continue;
        }
        if(!dfs(u, 1-now)) {
            return false;
        }
    }
    return true;
}

int main() {
    ll n, m;
    cin >> n >> m;    

    G.resize(n);
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    
    color.assign(n, -1);
    bool nibuGraph = true;
    rep(v, n) {
        if(color[v] != -1) {
            continue;
        }
        if(!dfs(v)) {
            nibuGraph = false;
        }
    }

    if(nibuGraph) {
        ll cntW = 0, cntB = 0;
        rep(v, n) {
            if(color[v]) {
                cntB++;
            }
            else {
                cntW++;
            }
        }
        out(cntW*cntB - m);
    }
    else {
        out(n*(n-1)/2 - m);
    }
    
    re0;
}