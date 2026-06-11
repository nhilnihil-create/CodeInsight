#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

const long long int mod = 1e9+7 ;

int a[200001] , b[200001] ={} , c[200001] ;

long long int dp[200000] ;

int main()
{
	int n , i ;
	cin >> n ;
	
	for ( i=1 ; i<=n ; i++)
		cin >> a[i] ;
	
	c[1] = a[1] ;
	int total = 1 ;
	
	for( i=2 ; i<=n ; i++){
		if ( a[i] != c[total] ) 
			c[++total] = a[i] ;
	}
	
	for ( i=1 ; i<= total ; i++ ){
		if ( i==1 ) {
			b[c[i]] = i ;
			dp[1] = 1 ;
			continue ;
		}
		if (b[c[i]])
			dp[i] = (dp[i-1] + dp[b[c[i]]]) % mod ;
		else
			dp[i] = dp[i-1] ;
		b[c[i]] = i ;
		
	}
	
	cout << dp[total] ;
		
	
	return 0 ;
}