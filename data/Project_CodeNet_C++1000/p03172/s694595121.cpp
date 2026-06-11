#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
ll n, k, a[109], dp[109][100009], p[100009];
ll get(int ind) {
    if(ind == -1)
        return 0;
    return p[ind];
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++) {
        p[0] = 1;
        for(ll candies=1;candies<=k;candies++)
            p[candies] = (p[candies - 1] + dp[i - 1][candies]) % mod;
        for(ll candies=0;candies<=k;candies++) {
            //cout<<i<<" "<<candies<<" "<<p[candies]<<" "<<a[i]<<" "<<get(max(0ll, candies-a[i]) - 1)<<endl;
            dp[i][candies] += (p[candies] - get(max(0ll, candies-a[i]) - 1));
            if(dp[i][candies] < 0)
                dp[i][candies] += mod;
            //for(int l=max(0ll, candies-a[i]);l<=candies;l++)
            //    dp[i][candies] += dp[i - 1][l];
            //for(int last = 0;last <= min(a[i], candies); last++) {
            //    dp[i][candies] += dp[i - 1][candies - last];
            //}
            //cout<<dp[i][candies]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[n][k];
}
