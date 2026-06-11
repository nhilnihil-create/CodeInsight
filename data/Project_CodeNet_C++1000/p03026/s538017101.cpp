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

vvl G;
vl c, d;
ll id = 0;

void dfs(ll v, ll p = -1) {
    // 行きの処理はこのへんに書く
    d[v] = c[id];
    id++;
    for(auto u : G[v]) {
        if(u == p) {
            continue;
        }
        dfs(u, v);
        // 帰りの処理はこのへんに書く
    }
}

int main() {
    ll n;
    cin >> n;    

    G.resize(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    c.resize(n);
    rep(i, n) {
        cin >> c[i];
    }
    sort(rall(c));

    ll M = 0;
    exrep(i, 1, n-1) {
        M += c[i];
    }
    out(M);

    d.resize(n);
    const ll root = 0;
    dfs(root);

    rep(i, n) {
        cout << d[i];
        if(i < n-1) {
            cout << " ";
        }
    }

    cout << endl;
    re0;
}