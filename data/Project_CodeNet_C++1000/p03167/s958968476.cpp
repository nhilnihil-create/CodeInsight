#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    int n,m;
    cin>>n>>m;
    long dp[n][m];
   // memset(dp,1,sizeof(dp));
    vector<string> v;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        v.push_back(s);
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0) continue;
            if(i==0||j==0)
            {
                if(v[i][j]=='.') {
                    if((i!=0 && dp[i-1][j]==1)||(j!=0 && dp[i][j-1]==1))
                    dp[i][j]=1; 
                    else dp[i][j]=0;
                }
                else dp[i][j]=0;
                
                continue;
            }
            if(v[i][j]=='.')
            {
                dp[i][j]=dp[i-1][j]%1000000007+dp[i][j-1]%1000000007;
            }
            else dp[i][j]=0;
            
            dp[i][j]%=1000000007;
        }
    }
    // for(int i=0;i<n;i++)
    // {for(int j=0;j<m;j++)
    // cout<<v[i][j]<<" "; cout<<endl;}
    // for(int i=0;i<n;i++)
    // {for(int j=0;j<m;j++)
    // cout<<dp[i][j]<<" "; cout<<endl;}
    cout<<dp[n-1][m-1]%1000000007<<endl;
 	return 0;
}
