#include<bits/stdc++.h>
#define int long long 
#define endl "\n"

using namespace std ; 
int mod = 1e9 + 7 ; 
const int N = 1e5 + 5 ; 
int dp[105][N] ; 
	
int n ,x ; 	
int a[N] ; 

              
signed main()
{
	ios_base::sync_with_stdio(false) ;	
	cin.tie(NULL);	
	
	cin >> n >> x; 

	for(int i = 0 ; i < n ; ++i)
		cin >> a[i] ; 
	dp[0][0] = 1 ; 
	dp[0][1] = -1  ; 

	for(int i = 0 ; i < n ; ++i)
	{
		int s = 0 ; 
		for(int j = 0; j <= x; ++j)
		{
			s = (s+ dp[i][j] + mod)%mod ;
				
			if(s > 0  )
			{
				dp[i+1][j] += s ;
				dp[i+1][j] %= mod  ; 
				if(j +a[i] +1< N)
				{	
					dp[i+1][j + a[i] +1]  -= s ;
					dp[i+1][j + a[i] +1] =(dp[i+1][j+a[i]+1] + mod)% mod ; 

				} 
			}
			
			
		}
	}
//	for(int i =0 ; i <=n ; ++i)
//	{
//		for(int j = 0 ; j<=x ;++j)
//			cout << dp[i][j] << " "  ; 
//		cout << endl ;
//	}
		
	int ans =0 ; 
	for(int i = 0 ; i <=x ; ++i)
	{
		ans += dp[n][i] ;
                if(ans<= 0 )
		{
			cout << 0 << endl ; 
			return 0 ;
		}
		if(ans >= mod )
			ans %= mod ; 
	}
	cout << ans%mod << endl ;

	
}                 	

















