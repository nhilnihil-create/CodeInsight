#include<bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define inf 1e18
#define fo(i,y,n,inc)	for(int i=y;i<n+y;i+=inc)
#define cin(t) int t;cin>>t
#define w(t) while(t--)
#define nl cout<<endl;
#define pb push_back
#define ft(i) (i&(-1*i))
#define arrIn(arr,size)		for(int i=0;i<size;i++){cin>>arr[i];}
#define arrOut(arr,size,seperater)	for(int i=0;i<size;i++){cout<<arr[i]<<seperater;}
using namespace std;

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int powmd(int a, int b) {
	if (b == 1)	return a;
	if (b == 0)	return 1;

	int half = powmd(a, b / 2);
	int ans = half * half;
	ans %= mod;
	if (b & 1) {
		ans *= a;
	}
	ans %= mod;
	return ans;
}

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int matrix[30][30];
int dp[25][2097160];
int n;

int solve(int index, int number) {

	if (index == n)	return 1;

	if (dp[index][number] != -1)	return dp[index][number];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (!((number >> i) & 1) && matrix[index][i] == 1) {
			ans += solve(index + 1, number + (1 << i));
			ans %= mod;
		}
	}
	return dp[index][number] = ans % mod;
}


int32_t main() {

	fastIO();

	cin >> n;
	fo(i, 0, n, 1) {
		fo(j, 0, n, 1) {
			cin >> matrix[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0) << endl;

	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;