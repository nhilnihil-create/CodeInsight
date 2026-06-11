#include <bits/stdc++.h>
#define ll long long int
#define fip(arr, si, en) for (ll i = si; i<en; i++){cin >> arr[i];}
#define fop(arr, si, en) for (ll i = si; i<en; i++){cout << arr[i] << " "; if(i==en-1) cout << endl;}
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>

using namespace std;

int f(vi &a, vi &b, vi &c, int n) {
	vector<vector<int>> dp(3, vi (n, INT_MIN));
	dp[0][0] = a[0]; dp[1][0] = b[0]; dp[2][0] = c[0];
	for (int i = 1; i < n; ++i)
	{
		dp[0][i] = a[i] + max(dp[1][i-1], dp[2][i-1]);
		dp[1][i] = b[i] + max(dp[0][i-1], dp[2][i-1]);
		dp[2][i] = c[i] + max(dp[0][i-1], dp[1][i-1]);
	}
	return max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1]));
}

int main(){
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	vi a(n),b(n),c(n);
	for (int i = 0; i < n; ++i)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
	cout << f(a,b,c,n);
}	