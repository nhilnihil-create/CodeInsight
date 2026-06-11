#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std ;
const int N =1e5 + 5 ;
int dp[105][N] ;
int pref[105][N] ; 
int mod = 1e9 +7 ;

signed main()
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;
	int n , x ;	 
	cin >> n >> x ;	
	vector<int> a(n);	
	for(int i =0 ; i < n ;++i)
		cin >> a[i] ; 
	for(int i = 0 ; i <=x ;++ i)
		pref[0][i] =1  ; 
	dp[0][0] =1 ; 
 	for(int i = 1 ; i <=n ; ++i)
	{
		for(int j =0 ; j <=x ; ++j)
		{
			int x = pref[i-1][j] ;
			int y = ((j-a[i-1]-1 >=0)?(pref[i-1][j-a[i-1]-1]):0)  ;
			dp[i][j] = (x-y + mod)%mod ; 
			if(j > 0 )
				pref[i][j] = (dp[i][j]+ pref[i][j-1])%mod ; 
			else if(j ==0 )
				pref[i][j] =1 ; 
		}
	}
//	for(int i = 0 ; i <=n ; ++i)
//	{
//		for(int j = 0 ; j <= x ; ++j)
//		{cout << dp[i][j] << " "  ; }
//		cout << endl ;
//	}
	cout << dp[n][x]%mod << endl ;

	                                                                                		
}

















