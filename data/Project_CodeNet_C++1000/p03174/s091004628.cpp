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
ll dp[23][1<<23];
int a[23][23];
ll pr[405];
main() {
    ios::sync_with_stdio(0);
    cin >> n;
    dp[0][(1<<n)-1] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
    for (int mask = 0; mask < (1<<n); mask++) {
        int cnt = __builtin_popcount(mask);
        if (cnt + i != n) continue;
        for (int j = 0; j < n; j++)
                    if ((1<<j)&mask && a[i][j]) {
            (dp[i+1][mask^(1<<j)] += dp[i][mask])%=mod;
        }
    }
    cout << dp[n][0];
}
