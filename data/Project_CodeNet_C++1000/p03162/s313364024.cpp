#include<bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 

void solve()
{
    	   
 int n; cin>>n;
 int a[n][3];   for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
 
 int dp[n][3];
 dp[0][0]=a[0][0];
 dp[0][1]=a[0][1];
 dp[0][2]=a[0][2];
 
 for(int i=1;i<n;i++)
 {
     dp[i][0]=max(a[i][0]+dp[i-1][1],a[i][0]+dp[i-1][2]);
     dp[i][1]=max(a[i][1]+dp[i-1][0],a[i][1]+dp[i-1][2]);
     dp[i][2]=max(a[i][2]+dp[i-1][0],a[i][2]+dp[i-1][1]);
 }
 
 int ans=max(dp[n-1][0],dp[n-1][1]);
 ans=max(ans,dp[n-1][2]);
 cout<<ans;
}
 
 
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
          solve();
    }
    
    
        return 0;
	
}