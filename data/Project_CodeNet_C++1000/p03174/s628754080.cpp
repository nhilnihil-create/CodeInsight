#include <iostream>
#include <vector>
// #include <string>
// #include <climits>
// #include <algorithm>
// #include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n,mod = 1e9+7;
	cin >> n;

	vector<vector<int> > comp(n,vector<int>(n,0));
	vector<int> dp(1<<n,0);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> comp[i][j];
	dp[0] = 1;
	
	for(int i=0;i<(1<<n)-1;i++){
		int m = __builtin_popcount(i);
		for(int j=0;j<n;j++){
			int temp = i|(1<<j);
			if(comp[m][j]&&temp!=i)
				dp[temp] = (dp[i]+dp[temp])%mod;
 		}
	}
	cout << dp[(1<<n)-1];
}