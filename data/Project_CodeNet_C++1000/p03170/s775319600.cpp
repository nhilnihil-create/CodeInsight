#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	bool dp[k+1]={false};
    for(int i=1;i<=k;i++)
    {
    	dp[i]=false;
    	for(int j=0;j<n;j++)
    	{
    		if(arr[j]<=i && dp[i-arr[j]]==false)
    		    dp[i]=true; 		    
		}
	}
	if(dp[k]==true)
	    cout<<"First\n";
	else
	   cout<<"Second\n";
}