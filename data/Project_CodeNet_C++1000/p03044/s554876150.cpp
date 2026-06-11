#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

vector<vector<pair<int,int>>>g;
vector<int>res;
void dfs(int v,int p,int c) {
    res[v] = c;
    for(auto e : g[v]) {
        if(e.first == p) continue;
        if(e.second % 2==0) dfs(e.first,v,c%2);
        else dfs(e.first,v,(c+1)%2);
    }
}
int main() {
    int n;
    cin >> n;
    g.resize(n);
    rep(i,n-1) {
        int v,u,w;
        cin >> v >> u >> w;
        v--;u--;
        g[v].push_back({u,w});
        g[u].push_back({v,w});
    }
    res.resize(n);
    dfs(0,-1,0);
    rep(i,n) {
        cout << res[i] << endl;
    }
}