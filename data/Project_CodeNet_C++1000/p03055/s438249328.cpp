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
    ll n;
    cin >> n;
    
    vector<vector<P>> G(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        a--;  b--;
        G[a].emplace_back(make_pair(b, 1));
        G[b].emplace_back(make_pair(a, 1));
    }
    
    vl dist1(n, -1);  // dist1[v] : 頂点vの頂点0からの距離
    queue<ll> Q1; 
    dist1[0] = 0;
    Q1.push(0);
    while(!Q1.empty()) {
        ll v = Q1.front();
        Q1.pop();
        for(auto p : G[v]) {
            ll u = p.first;
            ll cost = p.second; 
            if(dist1[u] != -1) {
                continue;
            }
            dist1[u] = dist1[v] + cost;
            Q1.push(u);
        }
    }
    
    ll vertex1 = 0;  // 頂点0からの距離が最大の頂点
    rep(v, n) {
        if(dist1[vertex1] < dist1[v]) {
            vertex1 = v;
        }
    }
    
    vl dist2(n, -1);  // dist2[v] : 頂点vの頂点vertex1からの距離
    queue<ll> Q2;
    dist2[vertex1] = 0;
    Q2.push(vertex1);
    while(!Q2.empty()) {
        ll v = Q2.front();
        Q2.pop();
        for(auto p : G[v]) {
            ll u = p.first;
            ll cost = p.second; 
            if(dist2[u] != -1) {
                continue;
            }
            dist2[u] = dist2[v] + cost;
            Q2.push(u);
        }
    }
 
    ll vertex2 = vertex1;  // 頂点vertex1からの距離が最大の頂点
    ll TreeDiameter = 0;  // 木の直径
    rep(v, n) {
        if(dist2[vertex2] < dist2[v]) {
            vertex2 = v;
            TreeDiameter = dist2[v];
        }
    }
    
    if(TreeDiameter%3 == 1) {
        out("Second");
    }
    else {
        out("First");
    }
    
    re0;
}