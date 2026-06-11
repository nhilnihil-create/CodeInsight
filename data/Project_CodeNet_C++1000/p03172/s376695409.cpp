#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
int n,k;
const int mod = 1e9+7;
int dp[102][100005],pr[100005],a[102];
main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 0; i <= k; i++)
        pr[i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0;j <= k; j++) {
            dp[i][j] = pr[j] - (j > a[i] ? pr[j-a[i]-1] : 0);
            if (dp[i][j] < 0) dp[i][j] += mod;
        }
        pr[0] = dp[i][0];
        for (int j = 1; j <= k; j++) {
            pr[j] = pr[j-1] + dp[i][j];
            if (pr[j] >= mod) pr[j]-=mod;
        }
    }
        cout << dp[n][k];
}
