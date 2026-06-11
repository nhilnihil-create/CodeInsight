#include<iostream>
#include<algorithm>

using namespace std;

int dp[3001][3001];

int main(){
    string s, t;
    cin >> s >> t;
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans = "";
    int i = s.size(), j =t.size();
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]) {ans = ans+s[i-1]; i--; j--;}
        else if(dp[i-1][j]>=dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl; 
    return 0;
}