#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

int dp[(1<<21)];
int n;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>arr[i][j];
		}
	}	
	dp[0]=1;
	for(int i=0;i<(1<<n)-1;i++) {
		for(int j=0;j<n;j++) {
			int k = __builtin_popcount(i);
			if(arr[k][j] && ((i&(1<<j)) ==0)) {
				dp[(i|(1<<j))] = (dp[(i|(1<<j))]+dp[i])%MOD;
			}
		}
	}

	cout<<dp[(1<<n)-1];

	return 0;
}