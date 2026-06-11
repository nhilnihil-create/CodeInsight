#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int n,k;
const int mod = 1e9+7,N=1e5+5;
int dp[N][2];
vi adj[N];
void dfs(int v,int p) {
    dp[v][0] = dp[v][1] = 1;
    for (int i : adj[v])
    if (i != p) {
        dfs(i,v);
        dp[v][0] = (ll)dp[v][0]*(dp[i][1] + dp[i][0])%mod;
        dp[v][1] = (ll)dp[v][1]*dp[i][0]%mod;
    }

}
main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    cout << (dp[1][0] + dp[1][1])%mod;
}
