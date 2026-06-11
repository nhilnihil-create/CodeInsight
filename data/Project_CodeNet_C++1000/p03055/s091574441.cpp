#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int limit = 200005;
using edge = struct {int to; long long cost;};

int n;
vector<edge> tree[limit];
vector<long long> dist;

void dfs(int v, long long d = 0, int p = -1){
    dist[v] = d;
    for(auto &e : tree[v]) {
        if(e.to == p) continue;
        dfs(e.to, d + e.cost, v);
    }
}

vector<long long> calcDist(int s){
    dist = vector<long long>(n);
    dfs(s);
    return dist;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b;
        a--, b--;
        c = 1;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }
    vector<ll> dist1 = calcDist(0);
    int src = 0;
    ll mxDist = 0;
    rep(i,n){
        if(dist1[i] > mxDist){
            mxDist = dist1[i];
            src = i;
        }
    }
    vector<ll> dist2 = calcDist(src);
    rep(i,n){
        chmax(mxDist, dist2[i]);
    }
    if(mxDist%3 != 1) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}