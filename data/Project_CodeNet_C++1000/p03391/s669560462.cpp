#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2e5 + 10 ;

int a[MAX] , b[MAX] ;

int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	for(int i = 0 ; i < n ; ++i)
		cin>>a[i]>>b[i] ;
	long long ans = 0 , x = 2e9 ;
	bool flag = false ;
	for(int i = 0 ; i < n ; ++i)
	{
		ans += a[i] ;
		if(a[i] != b[i])
			flag = true ;
		if(a[i] > b[i])
			x = min(x , b[i]*1ll) ;
	}
	if(!flag)
		ans = 0 , x = 0 ;
	return cout<<ans - x<<"\n" , 0 ;
}