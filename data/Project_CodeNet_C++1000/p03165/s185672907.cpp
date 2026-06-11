

#include<iostream>
#include<bits/stdc++.h>
#include<array>
using namespace std;
#define int long long
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define endl "\n"
#define with_tests int t; cin >> t; while(t--){ solve(); cout << endl; }
#define without_tests solve(); cout << endl;
#define CEIL(x, y) (ll)ceil((long double)(x)/(long double)(y))
#define epsilon 1e-9 
typedef long long ll;
const int mod = 1e9+7;
const int N = 3e3+1;

// int dp[N][N];

void solve(){
    
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    string ans = "";
    while(i!=0 && j!=0){
        if(dp[i][j] == dp[i-1][j]){
            i = i-1;
        }
        else if(dp[i][j] == dp[i][j-1]){
            j = j-1;
        }
        else{
            ans += s[i-1];
            i = i-1, j = j-1;
        }
    }
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

int32_t main(){

    fast_cin;
    // with_tests;
    without_tests;

    return 0;
}
