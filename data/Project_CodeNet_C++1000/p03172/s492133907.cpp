#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
ll dp[105][100005], sum[100005];
ll add(ll u, ll v){
        if ((u + v) >= mod) return u + v - mod;
        else return u + v;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("VietCT.INP", "r")){
                freopen("VietCT.INP", "r", stdin);
                freopen("VietCT.OUT", "w", stdout);
        }
        ll n, k;
        cin >> n >> k;
        dp[0][0] = 1;
        sum[0] = 1;
        for (int i = 1; i <= k; i++) sum[i] = sum[i - 1] + dp[0][i];
        for (int i = 1; i <= n; i++){
                ll a;
                cin >> a;
                for (int j = 0; j <= k; j++){
                        if (j >= (a + 1)) dp[i][j] = add(sum[j] - sum[j - a - 1], mod);
                        else dp[i][j] = sum[j];
                }
                memset(sum, 0, sizeof(sum));
                sum[0] = dp[i][0];
                for (int j = 1; j <= k; j++) sum[j] = add(sum[j - 1], dp[i][j]);
        }
        cout << dp[n][k];
}
/*
*/