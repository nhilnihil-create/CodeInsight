# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007
# define INF 10000000000009
# define MAX 1000000



void solve(){
    lli n, k;
    cin >> n >> k;

    lli arr[n + 1];
    for(lli i = 1; i <= n; i++){
        cin >> arr[i];
    }

    lli dp[n + 1][k + 1];
    for(lli i = 0; i <= k; i++){
        dp[1][i] = (i <= arr[1] ? 1 : 0);
    }

    for(lli i = 2; i <= n; i++){
        for(lli j = 0; j <= k; j++){
            if(j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (MOD + dp[i][j - 1] + dp[i - 1][j] - ((j - arr[i] - 1 >= 0)
                    ? dp[i - 1][j - arr[i] - 1] : 0)) % MOD;
        }
    }

    cout << dp[n][k];

}


int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
