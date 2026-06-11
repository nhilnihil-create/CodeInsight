#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve(){
    int m,n,len=0;
    string s,t,ans="";
    cin>>s>>t;
    m=s.size(); n=t.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    int i=m,j=n;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans=s[i-1]+ans;
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve(); cout<<endl;
    return 0;
}