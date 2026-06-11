#include "bits/stdc++.h"
using namespace std;
 
int dp[100005];
 
int main(){
	int n,k;
	cin>>n>>k;
	 int arr[101];
	      for(int i=0;i<n;i++)
	      {
	      	cin>>arr[i];
		  }
	
	dp[0] = 0;
	for(int i = 1; i <= k; i++){
		dp[i] = 0;
		for(int j=0;j<n;j++)
	      	{   
	      	     
	      	   if(i>=arr[j]&&dp[i-arr[j]]==0)
				 {
				      dp[i]=1; 
					  break;	
				 }	
			}
	}
	
	if(dp[k] == 1)
		cout<<"First";
	else
		cout<<"Second";
	
}