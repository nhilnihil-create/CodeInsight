#include<bits/stdc++.h>
using namespace std; 
#define int long long int 
map<int,list<int>> m ;
int dp[1000001][2]; 
#define mod 1000000007 

int fn(int u,int color, int pr )
{


	if(dp[u][color] !=-1)
	{
		return dp[u][color] ; 
	}

	int ans1=1;
	int ans2 =1; 
	int ans3=1 ; 
	int ans=0 ; 

	if(color==0)
	{
		for(auto i : m[u])
		{
			if(i!=pr)
			{
				ans1=(ans1*fn(i,0,u))%mod; 
				ans2=(ans2*fn(i,1,u))%mod; 
			}
		}
		ans= (ans+ans2+ans1)%mod ; 
	}
	else
	{
		for(auto i : m[u])
		{
			if(i!=pr)
			ans3=(ans3*fn(i,0,u))%mod; 
		}

		ans= (ans+ans3)%mod ; 
	}

	return dp[u][color]=  ans%mod ; 

}




int32_t main()
{

	int n ; 
	cin>>n; 
	for(int i = 0; i < n-1; i++)
	{
		int x,y; 
		cin>>x>>y ; 
		m[x].push_back(y) ;
		m[y].push_back(x) ; 
	}
	memset(dp, -1, sizeof(dp)) ; 


	int h= fn(1, 0, -1) ; 

	cout<<h ; 

}