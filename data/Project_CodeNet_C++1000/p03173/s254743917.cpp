#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std ;                       
int dp[410][410] ; 
int inf = 1e18 ; 
signed main()
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 	
	
	int n ; 
	cin >> n ;
	
	vector<int> a(n+1) ;
	vector<int> pref(n+1) ; 	
	for(int i = 1;  i<= n ; ++i)
	{
		cin >> a[i] ;
		pref[i]= a[i] + pref[i-1] ; 
	//	dp[i][i] = a[i] ;  
	}		
	for(int d = 1 ; d< n ; ++d)
	{
		for(int i = 1 ; i <= n-d ; ++i)
		{
			int j = i + d ;	
			dp[i][j] = inf ; 
			for(int k = i ; k < j ; ++k )
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + pref[k] -pref[i-1] + pref[j] - pref[k]) ; 
		}
	}	
//	for(int i =0 ; i <= n ; ++i )
//	{
//	        for(int j = 1 ; j<= n ; ++j)
//		   	cout << dp[i][j] << " " ; 
//		cout << endl ;
//	}
	cout << dp[1][n] << endl; 
	                    	                                                                                		
}

















