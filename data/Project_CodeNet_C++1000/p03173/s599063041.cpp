#include<bits/stdc++.h>
using namespace std; 
#define int long long int 

int sum[1001][1001] ; 
int dp[1001][1001] ;
int prefix[100000000] ; 

#define inf 1000000000000000000

void sum1(int arr[], int n)
{
	for(int i=0 ; i< n ; i++)
	{
		for(int j=i ; j< n ;j++)
		{
			sum[i][j]= arr[j]+((j==i)?0 :sum[i][j-1]) ; 
		}
	}
	
}


int sumit(int i, int j)
{
	if(i==0)
	{
		return prefix[j] ; 
	}
	return (prefix[j]-prefix[i-1]) ; 
}


int fn(int arr[] ,int i ,int j,   int n )
{
	if(i>=j)
	{
		return 0 ; 
	}

	if(dp[i][j] !=-1)
	{
		return dp[i][j] ; 
	}


	int ans= inf; 
	for(int k=i ; k< j ; k++)
	{
		int z= sumit(i,j)+fn(arr, i, k, n)+fn(arr, k+1, j,n) ; 
		ans=min(ans, z) ; 
	}

	return dp[i][j]=  ans ; 


}



int32_t main()
{
	int n ; 
	cin>>n ; 
	int arr[n+1] ; 
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i] ; 
	}

	sum1(arr, n) ; 


	prefix[0]=arr[0] ; 
	for(int i=1 ; i<n ; i++)
	{
		prefix[i]=  prefix[i-1]+arr[i]; 
	}


	memset(dp, -1, sizeof(dp)) ; 

	cout<<fn(arr,0, n-1,n) ; 
}