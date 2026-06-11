#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
 
int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i=0; i<n; i++) {
		cin >> grid[i];
	}
	vector< vector<int> > dp(n, vector<int>(m, 0));
	
	for(int i=0; i<n; i++) {
		if (grid[0][i]=='#')
			break;
		dp[0][i]=1;
	}
	
	for(int i=0; i<n; i++) {
		if (grid[i][0]=='#')
			break;
		dp[i][0]=1;
	}
	
	for(int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (grid[i][j]=='.')
				dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
		}
	}
	
	cout << dp[n-1][m-1] << endl;
  	return 0;
}