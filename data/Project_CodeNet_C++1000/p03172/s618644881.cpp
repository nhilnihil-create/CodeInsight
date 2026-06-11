#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int dp[k+1];
	int ndp[k+1];
	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	for(int i=0;i<n;i++) {
		ndp[0]=dp[0];
		for(int i=1;i<=k;i++) {
			ndp[i]=dp[i]-dp[i-1];
		}
		for(int j=0;j<k;j++) {
			int ll = j+1;
			int rr = min(k, j+arr[i]);
			ndp[ll]+=dp[j];
			if(rr+1<=k)
				ndp[rr+1]-=dp[j];
		}
		dp[0]=ndp[0];
		for(int i=1;i<=k;i++) {
			dp[i]=(dp[i-1]+ndp[i]+MOD)%MOD;
		}
	}

	cout<<dp[k];

	return 0;
}