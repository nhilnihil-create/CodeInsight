#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
ll n, dp[409][409], p[409];
ll ans;
int main() {
    cin>>n;
    vector<ll> a(n + 1);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        p[i] = p[i - 1] + a[i];
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l <= n - len + 1; l++) {
            int r = l + len - 1;
            dp[l][r] = 1000000000000000;
            for(int cut = l;cut < r; cut++) {
                ll suml = p[cut] - p[l - 1];
                ll sumr = p[r] - p[cut];
                dp[l][r] = min(dp[l][r], dp[l][cut] + dp[cut + 1][r] + p[r] - p[l - 1]);
            }
        }
    }
    cout<<dp[1][n];
}
