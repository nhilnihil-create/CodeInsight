#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;


int main()
{
    fast
    string s,t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            
        }
    }
    int i=n;
    int j=m;
    string res = "";
    int len = dp[n][m];
    res.resize(len);
    while(i>=1 && j>=1){
        if(s[i-1]==t[j-1]){
            res[len-1] = s[i-1];
            i--;
            j--;
            len = len-1;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else
            {
                j--;
            }
            
        }
    }
    cout << res <<'\n';
    return 0;
}