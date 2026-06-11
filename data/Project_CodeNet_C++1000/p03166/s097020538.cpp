# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007

vector<int> g[100001];
int dp[100001];

int dfs(int nd){
    if(dp[nd] != -1)
        return dp[nd];

    int res = 0;
    for(auto nbr : g[nd]){
        res = max(res, 1 + dfs(nbr));
    }

    return dp[nd] = res;

}


void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++){
        ans = max(ans, dfs(i));
    }

    cout << ans;

}


int main(){
    solve();
}
