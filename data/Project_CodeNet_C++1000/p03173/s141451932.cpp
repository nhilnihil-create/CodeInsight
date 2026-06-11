#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 4e2+5;

int dp[N][N];
int n;
int arr[N];
int pre[N];

int solve(int l, int r) {
	if(l==r)
		return 0;
	if(r-l==1) {
		return arr[l]+arr[r];
	}
	if(dp[l][r]>0)
		return dp[l][r];
	int cval = 1e18;
	for(int i=l;i<r;i++) {
		int cans = solve(l,i) + solve(i+1, r)+pre[r+1]-pre[l];
		cval = min(cans, cval);
	}
	return dp[l][r]=cval;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	pre[0]=0;
	for(int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+arr[i-1];
	}

	cout<<solve(0, n-1);

	return 0;
}