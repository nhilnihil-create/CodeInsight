#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    vector<vector<int> >dp(s.length()+1,vector<int>(t.length()+1));
    for(int i=0;i<s.length();i++){
        for(int j=0;j<t.length();j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    string ans = "";
    int j = t.length();
    int i = s.length();
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans = s[i-1] + ans;
            i--;
            j--;
        }else{
            if(dp[i][j] == dp[i-1][j]){
                i--;
            }else{
                j--;
            }
        }
    }
    cout << ans << endl;
}