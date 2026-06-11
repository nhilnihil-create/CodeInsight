#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll N = 303 ;
int dp[303][303][303], n, k;
string s ;
int main()
{
	for(int i = 0 ; i < N ; i ++)
		for(int j = 1 ; j < N ; j ++)
			dp[i][j][j] = 1 ; 
	cin >> s >> k ; 
	n = s.size() ;
	for(int jump = 1 ; jump <= n ; jump ++){
		for(int i = 1 ; i + jump <= n ; i ++){
			for(int u = 0 ; u <= n ; u ++){
				dp[u][i][i+jump] = max(dp[u][i+1][i+jump], dp[u][i][i+jump-1]) ;
				if(u-(s[i-1]!=s[i+jump-1])>=0)
					dp[u][i][i+jump] = max(dp[u][i][i+jump], dp[u-(s[i-1]!=s[i+jump-1])][i+1][i+jump-1]+2) ;
			}
		}
	}
	cout << dp[k][1][n] ;
}