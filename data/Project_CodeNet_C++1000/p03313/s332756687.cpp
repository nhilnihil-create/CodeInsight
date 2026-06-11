#include <bits/stdc++.h>

using namespace std ;

const int MAXN = 19 , MAX = (1 << 19) ;

int arr[MAX] ;
pair<int , int> ans[MAX] ;
int n ;

void Merge(pair<int , int>&p , pair<int , int>p2)
{
	if(p2.first > p.first)
	{
		p.second = p.first , p.first = p2.first ;
		if(p2.second > p.second)
			p.second = p2.second ;
	}
	else if(p2.first > p.second)
		p.second = p2.first ;
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	for(int i = 0 ; i < (1 << n) ; ++i)
	{
		cin>>arr[i] ;
		ans[i].first = arr[i] ;
		ans[i].second = 0 ;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		for(int mask = 0 ; mask < (1 << n) ; ++mask)
		{
			if((mask & (1 << i)))
				Merge(ans[mask] , ans[mask ^ (1 << i)]) ;
		}
	}
	for(int i = 1 ; i < (1 << n) ; ++i)
	{
		if(ans[i-1].first + ans[i-1].second > ans[i].first + ans[i].second)
			ans[i] = ans[i-1] ;
		cout<<ans[i].first + ans[i].second<<"\n" ;
	}
	return 0 ;
}		