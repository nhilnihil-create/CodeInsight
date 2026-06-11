#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<vector<int>> dp(n, vector<int>(3));
    int a, b, c;
    cin >> a >> b >> c;
    dp[0][0] = a; dp[0][1] = b; dp[0][2] = c;
    for(int i=0; i+1<n; ++i){
        cin >> a >> b >> c;
        dp[i+1][0] = max(dp[i][1], dp[i][2]) + a; 
        dp[i+1][1] = max(dp[i][2], dp[i][0]) + b; 
        dp[i+1][2] = max(dp[i][0], dp[i][1]) + c; 
    }
    int res = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    cout << res << endl;
    return 0;
}