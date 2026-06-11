#include <bits/stdc++.h>
using namespace std;
#define maxi 10000

string lcs(string &s,string &t){
    int n=s.length();int m=t.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=m;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int l=dp[n][m];
    string ans="";
    //cout<<l;
    int i=n,j=m;
    //cout<<t<<endl;
    while(l!=0){
        if(s[i-1]==t[j-1]&&i<=n&&j<=m){
            ans.push_back(s[i-1]);i--;j--;l--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }
    //cout<<i<<" "<<j<<endl;
    reverse(ans.begin(),ans.end());return ans;
}

int main() {
    string s,t;cin>>s>>t;
    cout<<lcs(s,t);
}
