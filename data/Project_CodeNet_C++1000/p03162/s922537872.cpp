#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
const int N = 2e5+5,M = 1e6+5;
int h[N],n,c,ans[N];
const int inf = 1e18;
int a[N][3];
int dp[N][3];
main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
        cin >> a[i][j];
    for (int i = 0;i < 3; i++)
        dp[1][i] = a[1][i];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
            if (j != k)
            dp[i][j] = max(dp[i][j],a[i][j] + dp[i-1][k]);
    }
    cout << max({dp[n][0],dp[n][1],dp[n][2]});
}
