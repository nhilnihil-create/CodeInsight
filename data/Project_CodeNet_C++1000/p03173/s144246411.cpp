# include <bits/stdc++.h>
using namespace std;
# define lli long long int
# define MOD 1000000007
# define INF 10000000000009


void solve(){
    lli n;
    cin >> n;

    lli arr[n];
    lli pref[n];
    for(lli i = 0; i < n; i++){
        cin >> arr[i];
        pref[i] = (i == 0 ? arr[i] : pref[i - 1] + arr[i]);
    }

    lli dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(lli i = 1; i < n; i++){
        lli r = 0, c = i;
        while(c < n){
            lli minVal = INF;
            for(lli k = r; k < c; k++){
                minVal = min(minVal, dp[r][k] + dp[k + 1][c] + (r == 0 ? pref[c] : pref[c] - pref[r - 1]));
            }
            dp[r][c] = minVal;
            r++, c++;
        }
    }

    cout << dp[0][n - 1];


}


int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
