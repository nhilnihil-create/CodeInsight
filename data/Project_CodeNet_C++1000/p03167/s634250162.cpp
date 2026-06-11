#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long int ll;

int mod = 1e9 + 7;
char mat[1001][1001];
int n, m;
int dp[1001][1001];

int find(int i, int j) {
	if (i == n - 1 && j == m - 1)
		return 1;

	if (i >= n || j >= m)
		return 0;

	if (mat[i][j] == '#')
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = (find(i + 1, j) + find(i, j + 1)) % mod;
	return dp[i][j] % mod;
}

int main() {
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	cout << find(0, 0);
	return 0;
}

