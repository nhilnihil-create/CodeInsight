#include<bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 

void solve()
{
    	   
 int n,k; cin>>n>>k;
 int a[n]; for(int i=0;i<n;i++)cin>>a[i];
 
 int dp[n];
 dp[0]=0;
 int cnt;
 
 dp[1]=abs(a[1]-a[0]);
 for(int i=2;i<n;i++)
 {
     
     int temp=INT_MAX;
     cnt=1;
     
     while(cnt<=k&&(i-cnt)>=0)
     {
         temp=min(temp,dp[i-cnt]+abs(a[i]-a[i-cnt]));
         cnt++;
     }
     dp[i]=temp;
 }
 cout<<dp[n-1];
  
 
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