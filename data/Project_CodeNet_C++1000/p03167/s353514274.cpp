#include <bits/stdc++.h>
using namespace std;

long long int dp[1001][1001];      /// dp[i][j] = count of way to get from (0, 0) to (n, m)
char grid[1001][1001];
const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>> m;

    for(int i = 0; i<n; i++)
        cin>>grid[i];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            }


            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }

            if(i > 0)
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            if(j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;

        }
    }

    cout<<dp[n-1][m-1]<<endl;

    return 0;
}

