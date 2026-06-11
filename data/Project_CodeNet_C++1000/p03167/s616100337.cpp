#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	
	int h,w,i,j,mod=1e9+7;
	cin>>h>>w;
	
	char arr[h][w];
	
	for(i=0;i<h;i++)
	    for(j=0;j<w;j++)
	        cin>>arr[i][j];
	
	long long dp[h][w]={0};
	
	for(int i=0;i<h;i++)
	{
	    for(int j=0;j<w;j++)
	    {
	        if(i==0&&j==0)
    	        dp[0][0]=1;
    	        
	        else if(arr[i][j]=='#')
	            dp[i][j]=0;
	            
	        else if(i==0)
    	        dp[i][j]=dp[i][j-1];
    	        
	        else if(j==0)
    	        dp[i][j]=dp[i-1][j];
    	        
	        else 
    	        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
	    }
	}
	cout<<dp[h-1][w-1];
	
	
	return 0;
}