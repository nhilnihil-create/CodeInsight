# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007

vector<int> g[100001];
lli dp[100001][2];

lli findAll(int x, int col, int par){

    if(dp[x][col] != -1){
        return dp[x][col];
    }

    bool leaf = true;

    lli k1 = 1, k2 = 1;
    for(auto nbr : g[x]){
        if(nbr != par){
            leaf = false;
            k1 *= findAll(nbr, 0, x);
            k1 %= MOD;
            if(col == 0){
                k2 *= findAll(nbr, 1, x);
                k2 %= MOD;
            }
        }
    }

    if(leaf){
        return 2 - col;
    }

    lli ans;
    if(col == 0)
        ans = k1 + k2;
    else
        ans = k1;
    ans %= MOD;
    return dp[x][col] = ans;

}

void solve(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << findAll(1, 0, -1) << "\n";
}


int main(){
    solve();
}
