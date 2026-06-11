#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,q,ans;
char s[305];
int dp[305][305][305];
int main(void){
    cin>>s>>q;
    n=strlen(s);
    for(int i=0;i<n;i++)dp[q][i][i]=1;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])dp[q][i][i+1]=2;
        else dp[q][i][i+1]=1;
    }
    for(int i=0;i<n-1;i++)if(s[i]!=s[i+1]&&q>0)dp[q-1][i][i+1]=2;
    for(int k=1;k<n;k++){
        for(int i=0;i+k<n;i++){
            int l=i,r=i+k;
            for(int j=0;j<=q;j++){
                if(s[l]==s[r]){
                    dp[j][l][r]=max(dp[j][l][r],dp[j][l+1][r-1]+2);
                }else if(j<q){
                    dp[j][l][r]=max(dp[j][l][r],dp[j+1][l+1][r-1]+2);
                }
                dp[j][l][r]=max(dp[j][l][r],max(dp[j][l+1][r],dp[j][l][r-1]));
            }
        }
    }
    for(int i=0;i<=q;i++)ans=max(ans,dp[i][0][n-1]);
    cout<<ans<<endl;
}