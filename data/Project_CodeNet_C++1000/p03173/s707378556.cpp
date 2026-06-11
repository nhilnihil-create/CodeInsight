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
ll dp[405][405];
int a[405];
ll pr[405];
main() {
    ios::sync_with_stdio(0);
    cin >> n ;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pr[i] = a[i];
    }
    for (int i = 1; i <= n;i++)
        pr[i] += pr[i-1];
    for (int r = 1; r <= n; r++)
    for (int l = r-1; l > 0; l--) {
        dp[l][r] = 10000000000000000;
        for (int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r],dp[l][i] + dp[i+1][r] + pr[r] - pr[l-1]);
    }
    cout << dp[1][n];

}
