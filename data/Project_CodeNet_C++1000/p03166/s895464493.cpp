#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
string s,t;
const int N = 1e5+5;
vi adj[N];
bool vis[N];
vi path;
void dfs(int v) {
    vis[v] = 1;
    for (int i : adj[v])
        if (!vis[i])dfs(i);
    path.pb(v);

}
int dp[N];
main() {
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0,a,b; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i =1 ; i <= n; i++) {
            if (!vis[i])
            dfs(i);
    }
    reverse(path.begin(),path.end());
    for (int i:path) {
        for (int j : adj[i])
            dp[j] = max(dp[j],dp[i] + 1);
    }
    cout << *max_element(dp,dp+n+1);
}
