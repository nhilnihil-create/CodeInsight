#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e5+5;

int n,k;
int dp[N];
int arr[105];

int solve(int k) {
	if(dp[k]>=0) {
		return dp[k];
	}
	if(k<arr[0]) {
		return dp[k]=0;
	}
	for(int i=0;i<n;i++) {
		if(k-arr[i]>=0)
		if(solve(k-arr[i])==0) {
			return dp[k]=1;
		}
	}
	return dp[k]=0;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	memset(dp, -1, sizeof(dp));
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}

	if(solve(k)) {
		cout<<"First";
	}
	else {
		cout<<"Second";
	}

	return 0;
}