#include <bits/stdc++.h>
using namespace std;



int n, m ;
char a[1001][1001];
int b[1001][1001];

int dp[1001][1001] ;

int f(int i, int j) {
	if (dp[i][j] != -1)
		return dp[i][j];

	if (i == n - 1 && j == m - 1) {
		// b[i][j] = 1;
		// for (int ii = 0; ii < n; ii++)
		// 	for (int jj = 0; jj < m; jj++)
		// 		cout >> b[ii][jj];
		return 1;
	}
	if (i >= n || j >= m)
		return 0;
	if (a[i ][j] == '#') return 0;
	int count = 0;
	b[i][j] = 1;
	count += f(i + 1, j);
	count += f(i, j + 1);
	b[i][j] = 0;

	return dp[i][j] = count % 1000000007;
}


int main()
{	

	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	//memset(b, '.', sizeof b);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	// for (int i = 0; i < n; i++)
	// 	for (int j = 0; j < m; j++)
	// 		b[i][j] = 0;


	cout << f(0, 0);

	//cout << ans;
	return 0;
}