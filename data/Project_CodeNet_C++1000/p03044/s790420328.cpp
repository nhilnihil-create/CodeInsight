#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);

vecl color(100010,-1),dist0(100010);

void dfs(vector<vector<Pl>> &G, int s) {
    for(auto p : G[s]) {
        int v = p.first;
        ll c = p.second;
        if(color[v] != -1) continue;
        if((dist0[s]+c)%2 == 0) color[v] = 0;
        else color[v] = 1;
        dist0[v] = dist0[s]+c;
        dfs(G,v);
    }
}

int main() {
    int N; cin >> N;
    vector<vector<Pl>> G(N);
    
    REP(i,N-1) {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--;v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    
    color[0] = 0;
    dfs(G,0);
    REP(i,N) cout << color[i] << endl;
}