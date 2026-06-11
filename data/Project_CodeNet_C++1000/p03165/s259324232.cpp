#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int
#define F first
#define S second
#define pb push_back
#define M 1000000007
#define inf 1e18
#define endl "\n"
#define jam(x) cout<<"Case #"<<x<<": "

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

std::vector<std::vector<int>> dp;

int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	dp.resize( n + 1 , std::vector<int>(m + 1, 0)  );

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max( dp[i - 1][j] , dp[i][j - 1] );
			}
		}
	}

	//display2D(dp);

	int len = dp[n][m];
	string ans = "";
	int i = n, j = m;
	while ( len > 0 && i >= 0 && j >= 0) {
		if ( s1[i - 1] == s2[j - 1] ) {
			ans = s1[i - 1] + ans;
			i--;
			j--;
			len--;
		}
		else {
			if ( dp[i][j - 1] >= dp[i - 1][j]) {
				j--;
			} else {
				i--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}