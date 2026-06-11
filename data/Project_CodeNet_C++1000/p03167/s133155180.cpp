#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    
    const static int MOD = (int)1e9+7;
    int n, m; cin >> n >> m;
    vector<string>grid(n);
    vector<vector<int>>dp(n, vector<int>(m,0));

    for(int i = 0; i < n; i++){
        cin>>grid[i];
    }

    dp[n-1][m-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(grid[i][m-1] == '.'){
            dp[i][m-1] = dp[i+1][m-1];
        }
    }

    for(int i = m-2; i >= 0; i--){
        if(grid[n-1][i] == '.'){
            dp[n-1][i] = dp[n-1][i+1];
        }
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = m-2; j >= 0; j--){
            if(grid[i][j] == '.'){
                dp[i][j] = (dp[i+1][j]+dp[i][j+1])%MOD;
            }
        }
    }

    cout<<dp[0][0]<<endl;
}
