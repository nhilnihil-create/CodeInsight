#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
long long n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	long long ans = 0 ;
	for(long long i = 1ll ; i * i <= n ; ++i)
	{
		if((n - i) % i == 0)
		{
			long long x = (n - i) / i ;
			if(x == 0)
				continue ;
			if(n / x == n % x)
				ans += (n - i) / i ;
		}
	}
	return cout<<ans<<"\n" , 0 ;
}		