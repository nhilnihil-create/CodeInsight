#include <bits/stdc++.h>
#define ll long long
using namespace std;

int maxcost(ll arr[][3],ll n)
    {
        ll dp[n][3];
        
        for(ll i=0;i<3;i++)
            dp[0][i]=arr[0][i];
        
        for(ll i=1;i<n;i++)
        for(ll j=0;j<3;j++)
            {
                if(j==0)
                    dp[i][j] = arr[i][j]+ max(dp[i-1][j+1],dp[i-1][j+2]); 
                else if(j==1)
                    dp[i][j] = arr[i][j]+ max(dp[i-1][j-1],dp[i-1][j+1]); 
                else if(j==2)
                    dp[i][j] = arr[i][j]+ max(dp[i-1][j-1],dp[i-1][j-2]); 
            }
       
        ll a=0;  
        for(ll i=0;i<3;i++)
            a=max(a,dp[n-1][i]);
            
        return a;
    }

int main()
{
    ll n;
    cin>>n;
    
    ll arr[n][3];
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<3;j++)
            cin>>arr[i][j];
            
            
    cout<<maxcost(arr,n);
    
	return 0;
}