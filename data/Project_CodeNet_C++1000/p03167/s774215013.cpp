#include<bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 



 
 
 signed main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    
    
    int T; 
    T=1;
    //cin>>T;
    while(T--)
    {
        
       int n,m;  cin>>n>>m;
       int a[n][m];
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               char ch; cin>>ch;
               if(ch=='#')a[i][j]=-1;
               else a[i][j]=1;
           }
       }
       int dp[n+1][m+1];
       int mod=1000000007;
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++)
           {
               if(i==1&&j==1)dp[i][j]=1;
               else if(i==0||j==0)dp[i][j]=0;
               else if(a[i-1][j-1]==-1)dp[i][j]=0;
               else
               {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;   
               }
               //cout<<dp[i][j]<<" ";
           }
          // cout<<endl;
       }
       cout<<dp[n][m];
       
    }
    
        return 0;
	
}