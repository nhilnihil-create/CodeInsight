#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2e5 + 10 ;

long long A[MAX] , B[MAX] ;
int n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	long long sum1 = 0 , sum2 = 0 , sum = 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>A[i]>>B[i] ;
		if(A[i] > B[i])
			sum1 += A[i] - B[i] ;
		if(A[i] < B[i])
			sum2 += B[i] - A[i] ; 
		sum += A[i] ;
	}
	long long ans = 0ll ;
	if(sum1 == 0 && sum2 == 0)
		return cout<<0<<"\n" , 0 ;
	if(sum2 > sum1)
		return cout<<sum<<"\n" , 0 ;
	for(int i = 0 ; i < n ; ++i)
	{
		if(A[i] > B[i])
			ans = max(ans , sum - B[i]) ;
	}
	return cout<<ans<<"\n" , 0 ;
}		