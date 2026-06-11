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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n;
    cin >> n;
 
    vvl G(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].pb(b);
        G[b].pb(a);
    }
 
    vl c(n);
    rep(i, n) {
        cin >> c[i];
    }
    sort(all(c));

    vl deg(n);
    queue<ll> Q;
    rep(i, n) {
        deg[i] = G[i].size();
        if(deg[i] == 1) {
            Q.push(i);
        }
    } 
 
    vl d(n);    
    rep(i, n) { 
        ll v = Q.front();
        Q.pop();
        d[v] = c[i];
        for(auto u : G[v]) {
            deg[u]--;
            if(deg[u] == 1) {
                Q.push(u);
            }
        }
    }

    ll M = 0;
    rep(i, n-1) {
        M += c[i];
    }

    out(M);
    rep(i, n) {
        cout << d[i] << " ";
    }
 
    cout << endl;
    return 0;
}