#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define mod 1000000007



int main()
{
	
	FAST;
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
    	 int n ; cin>>n;
    	 int h[n+1], dp[n+1];
    	 for(int i=1; i<=n; i++) cin>>h[i];
    	 dp[1] = 0 , dp[2] = abs(h[2]-h[1]);
    	 for(int i=3; i<n+1; i++)
    	 {
    	 	dp[i] = min( dp[i-1]+abs(h[i]-h[i-1]) , dp[i-2]+abs(h[i]-h[i-2]));
		 }
		 cout<<dp[n]<<endl;
	}
		
    return 0;
}