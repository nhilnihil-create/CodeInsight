#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s, t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(s[i]==t[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    string ans = "";
    int i = 0;
    int j = 0;
    while(i<n && j<m){
        if(s[i]==t[j]){
            ans += s[i];
            i++;
            j++;
        }
        else{
            dp[i+1][j]>=dp[i][j+1]?i++:j++;
        }
    }
    cout<<ans;
    
}