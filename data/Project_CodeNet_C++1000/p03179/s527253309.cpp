#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

ll dp[3050][3050];
ll sum[3050][3050];

int main(){
	int n; cin >> n;
	string s; cin >> s;
	// init
	for( int j = 0; j <= n-1; ++j ) dp[0][j] = 1;
	for( int j = 0; j <= n-1; ++j ){
		sum[0][j+1] = ( sum[0][j] + dp[0][j] ) % mod;
		sum[0][j+1] %= mod;
	}
	for( int i = 0; i <= n-2; ++i ){
		for( int j = 0; j <= n-2-i; ++j ){
			if( s[i] == '>' ) dp[i+1][j] = sum[i][j+1];
			else dp[i+1][j] = ( sum[i][n-i] - sum[i][j+1] + mod ) % mod;
			// cout << "dp[" << i+1 << "][" << j << "]: " << dp[i+1][j] << endl; 
		}
		for( int j = 0; j <= n-1; ++j ){
			sum[i+1][j+1] = ( sum[i+1][j] + dp[i+1][j] ) % mod;
		}
	}
	cout << dp[n-1][0] << endl;
}