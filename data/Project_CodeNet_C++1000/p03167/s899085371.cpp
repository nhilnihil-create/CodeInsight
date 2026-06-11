#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define int long long int
#define F first
#define S second
#define pb push_back
#define M 1000000007
#define inf 1e18
#define endl "\n"
#define jam(x) cout<<"Case #"<<x<<": "
#define N 100005
void display2D( vector<vector<int> > &v ) {
	int n = v.size();
	int m = v[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	fileIO;
#endif

	int n, m;
	char temp;
	cin >> n >> m;
	std::vector < vector<int> > dp(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			if (temp == '#') dp[i][j] = 0;
		}
	}
	int filler = 1;
	for (int j = 0; j < m; j++) {
		if (dp[0][j] == 0) filler = 0;
		dp[0][j] = filler;
	}
	filler = 1;
	for (int i = 0; i < n; i++) {
		if (dp[i][0] == 0) filler = 0;
		dp[i][0] = filler;
	}



	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j] != 0) dp[i][j] = (dp[i - 1][j] % M + dp[i][j - 1] % M) % M;
		}
	}
	//display2D(dp);
	cout << dp[n - 1][m - 1] << endl;

	return 0;
}