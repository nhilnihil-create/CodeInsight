#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2e5 + 10 ;

int arr[MAX] , pref[MAX] , pref2[MAX] ;
int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	for(int i = 1 ; i <= n ; ++i)
		cin>>arr[i] ;
	for(int i = 1 ; i <= n ; ++i)
	{
		pref[i] = pref[i-1] + arr[i] ;
		pref2[i] = pref2[i-1] ^ arr[i] ;
	}
	long long ans = 0ll ;
	for(int i = 1 ; i <= n ; ++i)
	{
		int l = i , r = n ;
		long long ans2 = i-1 ;
		while(l <= r)
		{
			int mid = (l + r) >> 1 ;
			if((pref[mid] - pref[i-1]) == (pref2[mid] ^ pref2[i-1]))
				ans2 = mid , l = mid+1 ;
			else
				r = mid-1 ;
		}
		ans += (ans2*1ll-i*1ll+1ll) * 1ll ;
	}
	return cout<<ans<<"\n" , 0 ;
}		