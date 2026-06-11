#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
ll n, a[22][22];
int main() {
    cin>>n;
    vector<ll> dp((1<<n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n); mask++) {
        int i = __builtin_popcount(mask);
        for(int j=0;j<n;j++) {
            if(!(mask & (1 << j)) && a[i][j]) {
                int nxtmask = mask | (1 << j);
                dp[nxtmask] += dp[mask];
                dp[nxtmask] %= mod;
            }
        }
    }
    cout<<dp[(1<<n) - 1];
}
