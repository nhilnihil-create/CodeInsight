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

    ll i,j,n,m;
    string a,b;
    cin >> a;
    cin >> b;
    n = a.size();
    m = b.size();
    ll dp[n+1][m+1] = {{0}};
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string ans = "";
    i = n;
    j = m;
    while(dp[i][j]){
        while(dp[i][j]==dp[i-1][j]){
            i--;
        }
        while(dp[i][j]==dp[i][j-1]){
            j--;
        }
        if(dp[i][j]==dp[i-1][j]+1){
            ans = a[i-1] + ans;
            i--;
            j--;
        }
        else{
            ans = b[j-1] + ans;
            i--;
            j--;
        }
    }
    cout << ans << endl;
}

//    cout << fixed << setprecision(12);
