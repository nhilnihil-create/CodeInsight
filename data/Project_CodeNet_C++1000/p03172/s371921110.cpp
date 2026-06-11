
#include <iostream>
#include <vector>
// #define INF 
// #define MOD 1e9+7
#define F first
#define S second
using namespace std;



int main() {
	
	int n,k,MOD = 1e9+7;
	cin>>n>>k;
	long long arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	
	vector<vector<long long>>dp(n+1,vector<long long>(k+1,0));
	vector<long long>prev(k+1,0), nxt(k+1,0);
	
	
	for(int i=0;i<=n;i++)
	{
	    dp[i][0]=1;
	    nxt[0]=1;
	    //cout<<"1"<<" ";
	    for(int j=1;j<=k;j++)
	    {
	        
            
            if(i!=0)
            {
        	    if(j<=arr[i-1])
            	    dp[i][j] = prev[j];
        	    else
            	    dp[i][j] = (prev[j]%MOD - prev[j-arr[i-1]-1]%MOD + MOD)%MOD;
            }
    	    nxt[j] = (nxt[j-1]%MOD + dp[i][j]%MOD)%MOD;
    	    
    	    //cout<<dp[i][j]<<" ";
	    }
	    //cout<<endl;
	    prev=nxt;
	}
	cout<<dp[n][k];
	
	return 0;
}
