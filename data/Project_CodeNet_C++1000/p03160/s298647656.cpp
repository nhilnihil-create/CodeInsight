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

    ll i,n;
    cin >> n;
    ll a[n+1];
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    ll dp[n+1];
    dp[1] = 0;
    dp[2] = abs(a[2]-a[1]);
    for(i=3;i<=n;i++){
        dp[i] = min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout << dp[n] << endl;

}

//    cout << fixed << setprecision(12);
