#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define MAX 1005
#define MOD 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 3.14159265358979323846
#define Q ll _; cin >> _; while(_--)
#define endl "\n"
#define flush fflush(stdout);

int main(){

    fast

    ll i,n,k;
    cin >> n >> k;
    ll a[n+1];
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    ll dp[n+1];
    for(i=1;i<=n;i++){
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    for(i=2;i<=n;i++){
        ll x = max((ll)1,i-k);
        for(ll j=x;j<i;j++){
            dp[i] = min(dp[j]+abs(a[i]-a[j]),dp[i]);
        }
    }
    cout << dp[n] << endl;

}

//    cout << fixed << setprecision(12);
