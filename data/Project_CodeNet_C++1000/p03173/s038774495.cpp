#include <bits/stdc++.h>
using namespace std;
long long mod=pow(10,9)+7;

long long dp[500][500];
long long solve (int i,int j,int*arr,long long*pre)
{
	 if(i>=j)
	  return 0;
	  if(dp[i][j]!=-1)
	   return dp[i][j];
	   long long ans=1e18;
	  for(int k=i;k<j;k++)
	  {
	  	  long long a=solve(i,k,arr,pre);
		  long long b=solve(k+1,j,arr,pre);
		  ans=min(ans,a+b+pre[j+1]-pre[i]);
	  }
	  
	  return dp[i][j]=ans;
	  
}
int main() {	
	int t=1;
	//cin >> t;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (t--) {
	     int n;
	     cin>>n;
	     int*arr=new int[n];
	     memset(dp,-1,sizeof(dp));
	     for(int i=0;i<n;i++)
	     {
	     	cin>>arr[i];
		 }
		 long long*pre=new long long[n+1];
		 pre[0]=0;
		 for(int i=1;i<=n;i++)
	    {
	    	pre[i]=pre[i-1]+arr[i-1];
		}
		 
		 long long temp=solve(0,n-1,arr,pre);
		 cout<<dp[0][n-1];
		 
	 
      }
	} 
	
	
	