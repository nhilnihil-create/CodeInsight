# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007


vector<lli> g[100001];
lli dp[100001][2];

lli dfs(lli nd, lli par, lli col){
    if(dp[nd][col] != -1){
        return dp[nd][col];
    }

    lli k1 = 1, k2 = 1;
    bool leaf = true;
    for(auto nbr : g[nd]){
        if(nbr != par){
            leaf = false;
            k1 *= dfs(nbr, nd, 0), k1 %= MOD;
            if(col == 0)
                k2 *= dfs(nbr, nd, 1), k2 %= MOD;
        }
    }

    if(leaf)
        return 2 - col;

    lli ans = k1;
    if(col == 0)
        ans += k2, ans %= MOD;

    return dp[nd][col] = ans;
}

void solve(){
    lli n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(lli i = 0; i < n - 1; i++){
        lli x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << dfs(1, -1, 0);

}


int main(){
    lli t;
    t = 1;
    while(t--){
        solve();
    }
}
