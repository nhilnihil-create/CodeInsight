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
 
    ll n;
    cin >> n;

    ll h[n];
    ll dp[n];

    for(ll i=0; i<n; i++){
        cin >> h[i];
    }

    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);

    for(ll i=2; i<n; i++){

        ll op1 = dp[i-1] + abs(h[i] - h[i-1]);
        ll op2 = dp[i-2] + abs(h[i] - h[i-2]);
        
        dp[i] = min(op1, op2);
    }

    cout << dp[n-1];
}