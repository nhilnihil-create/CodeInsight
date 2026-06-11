#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
#define MOD 1e9+7
#define MAX_V

int main(){
    int n, z, w;
    cin >> n >> z >> w;

    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    /* dp[i][j]: 山札からi枚取られた状態で、j(先手 or 後手)からスタートしたときの最適値 */
    vector<vector<ll> > dp(n+1, vector<ll>(2));

    for(int i=n-1; i>=0; i--){
        /* 先手 */
        dp[i][0] = -INF_LL;
        ll pre_y;
        if(i==0){
            pre_y = w;
        } else {
            pre_y = a[i-1];
        }

        dp[i][0] = max(dp[i][0], abs(pre_y - a[n-1]));
        for(int j=i+1; j<n; j++) dp[i][0] = max(dp[i][0], dp[j][1]);

        /* 後手 */
        dp[i][1] = INF_LL;
        ll pre_x;
        if(i==0){
            pre_x = z;
        } else {
            pre_x = a[i-1];
        }
        dp[i][1] = min(dp[i][1], abs(pre_x - a[n-1]));
        for(int j=i+1; j<n; j++) dp[i][1] = min(dp[i][1], dp[j][0]);
    }
    
    cout << dp[0][0] << endl;



    return 0;
}