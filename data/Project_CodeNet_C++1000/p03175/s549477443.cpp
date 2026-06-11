#include <iostream>
#include <vector>
using namespace std;

int MOD = 1000000007;
long dp[2][100000];
vector<int> adj[100000];
void dfs(int i, int p){
    dp[0][i] = 1;
    dp[1][i] = 1;
    for(int v : adj[i]){
        if(v != p){
            dfs(v, i);
            dp[0][i] = (dp[0][i] * (dp[0][v] + dp[1][v]))%MOD;
        }
    }
    for(int v : adj[i]){
        if(v != p){
            dp[1][i] = (dp[1][i] * dp[0][v]) % MOD;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(0, -1);
    cout << (dp[0][0] + dp[1][0]) % MOD << '\n';
    return 0;
}


