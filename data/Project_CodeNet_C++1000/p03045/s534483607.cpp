#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

vector<vector<int>>g;

int n,m;
vector<bool>seen;
void dfs (int v,int p) {
    seen[v] = true;
    for(auto nv : g[v]) {
        if(nv==p) continue;
        if(!seen[nv]) dfs(nv,v);
    }
}

int main() {
    cin >> n >>m;
    g.resize(n);
    seen.resize(n);
    rep(i,n) seen[i] = false;
    rep(i,m) {
        int x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    rep(i,n) {
        if(seen[i]) continue;
        dfs(i,-1);
        ans++;
    }
    cout << ans << endl;
}