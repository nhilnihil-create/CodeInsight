#include <bits/stdc++.h>

#define ff first
#define ss second
#define int long long
#define MOD 1000000007

using namespace std;

int dp[25][2100000];

int popcount(int n){
    if (n==0)
        return 0;
    return 1 + popcount(n&(n-1));
}

signed main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<bool>> mat(n, vector<bool>(n));
    
    int in;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> in;
            mat[i][j] = (in==1);
        }
    }
    int mx = pow(2, n) - 1;
    
    for (int i=1; i<=mx; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;
    
    for (int i=1; i<=n; i++){
        for (int j=0; j<=mx; j++){
            dp[i][j] = 0;
            if (i == popcount(j)){
                for(int k=0; k<n; k++){
                    if ( (j&(1<<k)) && mat[i-1][k] ) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j - (1<<k)])%MOD;
                    }
                }
            }
        }
    }
    
    cout << dp[n][mx];

    return 0;
}