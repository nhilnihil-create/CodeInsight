#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    string ans = "";
    int i = n, j = m;
    while(i>0 && j>0){
        if (s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j]>=dp[i][j-1])
            i--;
        else
            j--;    
        
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}