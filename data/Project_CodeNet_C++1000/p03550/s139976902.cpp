#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2010 ;

int dp[MAX][MAX][2] , arr[MAX];
int n , x , y ;

int solve(int idx , int idx2 , int turn)
{
	int now ;
	if(idx2 == 0)
	{
		if(turn == 0)
			now = y ;
		else
			now = x ;
	}
	else
		now = arr[idx2] ;
	if(idx == n)
		return (abs(arr[idx] - now)) ;
	int &ret = dp[idx][idx2][turn] ;
	if(ret != -1)
		return ret ;
	if(turn == 0)
	{
		ret = solve(idx+1 , idx2 , turn) ;
		ret = max(ret , solve(idx+1 , idx , !turn)) ;
	}
	else
	{
		ret = solve(idx+1 , idx2 , turn) ;
		ret = min(ret , solve(idx+1 , idx , !turn)) ;
	}
	return ret ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>x>>y ;
	for(int i = 1 ; i <= n ; ++i)
		cin>>arr[i] ;
	memset(dp , -1 , sizeof(dp)) ;
	return cout<<solve(1 , 0 , 0)<<"\n" , 0 ;
}
