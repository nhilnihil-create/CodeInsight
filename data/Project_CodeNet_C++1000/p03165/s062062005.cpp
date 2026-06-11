#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    string s,t;
    cin>>s>>t;

    int dp[s.size()+1][t.size()+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==t[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }

    string ans = "";

    int i = s.size();
    int j = t.size();

    while(j>0){
        if(dp[i][j-1]==dp[i][j])j--;
        else if(dp[i][j]==dp[i-1][j])i--;
        else if(dp[i][j]==dp[i-1][j-1]+1){
            ans=t[j-1]+ans;
            j--;
            i--;
        }
    }

    cout<<ans<<endl;
}