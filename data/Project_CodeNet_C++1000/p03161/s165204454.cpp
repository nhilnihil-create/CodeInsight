#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define FI(z,n) for(int j=z; j<=n; j++)
#define FL(z,n) for(l j=z; j<=n; j++)
 
#define inf 10000000000
#define mod 1000000007
 
void In_Out(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}
 
 
int main(){
 
    // In_Out();
 
    ll n, k;
    cin >> n >> k;

    ll h[n];
    ll dp[n];

    for(ll i=0; i<n; i++){
        cin >> h[i];
    }

    dp[0] = 0;

    for(ll i=1; i<n; i++){

        dp[i] = INT_MAX;

        for(ll j=i-1; i-j<=k && j>=0; j--){
            dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));
        }
    }

    cout << dp[n-1];
}