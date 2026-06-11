#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n ;
	int arr[n] ;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i] ;
	int Max = -1 , now = 1 ;
	int idx = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		if(abs(arr[i]) > Max)
		{
			idx = i ;
			Max = abs(arr[i]) ;
			if(arr[i] >= 0)
				now = 1 ;
			else
				now = -1 ;
		}
		else if(abs(arr[i]) == Max && arr[i] >= 0)
			idx = i , now = 1 ;
	}
	vector< pair<int , int> >ans ;
	for(int i = 0 ; i < n ; ++i)
	{
		if(idx == i)
			continue ;
		ans.push_back({idx , i}) ;
		arr[i] += (now * Max) ;
	}
	int cnt = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		if(arr[i] >= 0)
			cnt++ ;
	}
	//debugging
	if(cnt != n && cnt != 0)
		while(1) ;
	if(cnt == n)
	{
		for(int i = 0 ; i < n-1 ; ++i)
			ans.push_back({i , i+1}) ;
	}
	else
	{
		for(int i = n-1 ; i >= 1 ; --i)
			ans.push_back({i , i-1}) ;
	}
	cout<<ans.size()<<"\n";
	for(auto &i : ans)
		cout<<i.first+1<<" "<<i.second+1<<"\n";
	return 0 ;
}