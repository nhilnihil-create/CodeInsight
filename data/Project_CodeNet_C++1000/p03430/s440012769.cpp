#include <bits/stdc++.h>
#define pb push_back
#define X first
#define Y second
#define ld long double 
//#define int long long 
using namespace std;

const int N = 333;

int dp[N][N][N] ; 

int32_t main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string s ; 
	cin >> s ;
	int n = s.size() ; 
	int _k ;
	cin >> _k ; 
	for(int i = 0 ; i < n ; i ++ ) for(int j = 0 ; j <= _k ; j ++ ) dp[i][i+1][j] = 1 ; 
	for(int l = 2 ; l <= n ; l ++ ) for(int i = 0 ; i + l <= n ; i ++ ) for(int k = 0 ; k <= _k ; k ++ ) 
	{
		int j = i + l ;
		dp[i][j][k] = max(dp[i+1][j][k],dp[i][j-1][k]) ; 
		if(s[i]==s[j-1]) dp[i][j][k] = max(2+dp[i+1][j-1][k],dp[i][j][k]) ; 
		else if(k) dp[i][j][k] = max(dp[i][j][k],2+dp[i+1][j-1][k-1]) ; 
	}
	cout << dp[0][n][_k] << endl ; 
}