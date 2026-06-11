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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

int n;
int arr[305];
double dp[305][305][305];

double solve(int i, int j, int k) {

	// base case
	if (i == 0 && j == 0 && k == 0) {
		return 0;
	}

	if (dp[i][j][k] != -1)	return dp[i][j][k];
	double oneProb = (double)i / (double)n;
	double twoProb = (double)j / (double)n;
	double threeProb = (double)k / (double)n;
	double zeroProb = double(n - i - j - k) / (double)n;
	double ans = 0;

	ans = 1;
	if (i > 0) ans += solve(i - 1, j, k) * oneProb;
	if (j > 0) ans += solve(i + 1, j - 1, k) * twoProb;
	if (k > 0) ans += solve(i, j + 1, k - 1) * threeProb;
	ans /= ((double)1 - zeroProb);
	return dp[i][j][k] = ans;
}


int32_t main() {

	fo(i, 0, 305, 1) {
		fo(j, 0, 305, 1) {
			fo(k, 0, 305, 1) {
				dp[i][j][k] = -1;
			}
		}
	}

	cin >> n;

	int oneCount, twoCount, threeCount;
	oneCount = twoCount = threeCount = 0;
	fo(i, 0, n, 1) {
		cin >> arr[i];
		if (arr[i] == 1) 	oneCount++;
		if (arr[i] == 2)	twoCount++;
		if (arr[i] == 3)	threeCount++;

	}

	cout << fixed << setprecision(9) << solve(oneCount, twoCount, threeCount); nl;
	return 0;
}

// cout << "Case #" << i << ": " << answer << endl;