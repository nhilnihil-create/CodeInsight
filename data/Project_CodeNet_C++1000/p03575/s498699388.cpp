#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int n,m;
vector<int>a;
vector<int>b;
vector<vector<bool>>g;
vector<bool>visited;

void dfs(int v) {
    if(visited[v]) return;
    visited[v] = true;
    rep(nv,n) {
        if(g[v][nv]) {
            dfs(nv);
        }
    }
}
int main() {
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    g.assign(n,vector<bool>(n,false));
    visited.resize(n);
    int ans = 0;
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        g[a[i]][b[i]] = true;
        g[b[i]][a[i]] = true;
    }
    rep(i,m) {
        rep(j,n) visited[j] = false;
        g[a[i]][b[i]] = false;
        g[b[i]][a[i]] = false;
        dfs(0);
        bool connected = true;
        rep(j,n) if(!(visited[j])) connected = false;
        if(!connected) ans++;
        g[a[i]][b[i]] = true;
        g[b[i]][a[i]] = true;
    }
    cout << ans << endl;
}




