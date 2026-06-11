#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define inf 10000000000099ll
#define mod 1000000007
#define prDouble(x) cout<<fixed<<setprecision(10)<<x

ll dp[3001][3001];
ll sum[3001][3001];

ll solve(vector<int>& v, int i, int j)
{
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	ll minCost = inf;
	for (int k = i; k < j; k++) {
		minCost = min(minCost, sum[i][j] + solve(v, i, k) + solve(v, k + 1, j));
	}
	return dp[i][j] = minCost;
}

void preProcessing(vector<int>& v, int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum[i][j] = v[j] + ((j == i) ? 0 : sum[i][j - 1]);
		}
	}
}

int main()
{
	FASTIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	memset(dp, -1, sizeof dp);
	vector<int> v(n + 1);
	loop(i, 1, n + 1) cin >> v[i];
	preProcessing(v, n);
	cout << solve(v, 1, n);
	return 0;
}

