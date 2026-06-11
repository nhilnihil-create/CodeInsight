#include <bits/stdc++.h>
using namespace std;  

int main() {
    int n, dp[26][101] = {}, ans, sum;
    string s;
    
    cin >> n;
    cin >> s;
    
    for ( int i = 0; i < n; i++ ) {
        dp[s[i]-'a'][i+1] ++;
        
        for ( int j = 0; j < 26; j++ ) {
            dp[j][i+1] += dp[j][i];
        }
    }
    
    ans = 0;
    for ( int i = 1; i < n; i++ ) {
        sum = 0;
        
        for ( int j = 0; j < 26; j++ ) {
            if (dp[j][i] > 0 && dp[j][n] - dp[j][i] > 0 ) {
                sum++;
            }
        }
        
        ans = max(ans, sum);
    }
    
    cout << ans << endl;
    
    return (0);
}