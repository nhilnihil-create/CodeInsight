#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e4 + 5 ;
int cost[] = {2,5,5,4,5,6,3,7,6} ;

int can[MAX], dig[MAX] , arr[12];
int m ;
void solve(int n)
{
	if(n == 0)
		return ;
	for(int i = m-1 ; i >= 0 ; --i)
	{
		if(n-cost[arr[i]-1] < 0)
			continue ;
		if(can[n-cost[arr[i]-1]] && dig[n] == dig[n-cost[arr[i]-1]]+1)
		{
			cout<<arr[i] ;
			solve(n-cost[arr[i]-1]) ;
			return ;
		}
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n>>m ;
	for(int i = 0 ; i < m ; ++i)
		cin>>arr[i] ;
	sort(arr , arr + m) ;
	can[0] = 1 ;
	for(int i = 0 ; i <= n ; ++i)
	{
		for(int j = 0 ; j < m ; ++j)
		{
			if(i-cost[arr[j]-1] < 0)
				continue ;
			can[i] |= can[i-cost[arr[j]-1]] ;
			if(can[i-cost[arr[j]-1]])
				dig[i] = max(dig[i] , dig[i-cost[arr[j]-1]]+1) ;
		}
	}
	solve(n) ;
	return 0 ;
}