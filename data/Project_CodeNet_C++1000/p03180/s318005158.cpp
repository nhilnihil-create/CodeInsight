#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
int n,a[16][16];
ll val[1<<16],dp[1<<16];
main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cin >> a[i][j];
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if ( (1<<i)&mask && (1<<j)&mask)
                val[mask] += a[i][j];
    }
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int sub = mask; sub; sub = (sub-1)&mask) {
            dp[mask] = max(dp[mask],val[sub] + dp[mask^sub]);
        }
    }
    cout << dp[(1<<n)-1];
}
