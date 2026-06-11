#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    double arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    double dp[n+1][n+1];

    for(int i = 0; i<=n; i++){
        dp[0][i] = 0;
    }

    dp[0][0] = 1;

    for(int i = 1; i<=n; i++){
        dp[i][0] = dp[i-1][0] * (1-arr[i-1]);
    }

    dp[0][0] = 1;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){

            if(j>i){
                dp[i][j] = 0;
            }

            dp[i][j] = dp[i-1][j]*(1-arr[i-1]) + dp[i-1][j-1]*arr[i-1];
        }
    }

    double ans = 0;

    for(int i = n/2+1; i<=n; i++){
        ans += dp[n][i];
    }

    cout << setprecision(10) <<  ans << "\n";

    return 0;
}