#include <bits/stdc++.h>
using namespace std;



int n, m ;
vector<int> a[100001];
int visited[100001];
int dp[100001] ;
int ans = 0;

int dfs(int s) {
	visited[s] = 1;
	if (dp[s] != 0)  {
		return	dp[s];

	}

	int z = 0;

	for (auto x : a[s])
		z = max(z,  1 + dfs(x));

	return dp[s] =  z;
}
void f() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for (int i = 1; i <= n; i++)
		if (visited[i] == 0)
			dfs(i);

	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
}

int main()
{	

	cin >> n >> m;
	memset(dp, 0, sizeof dp);

	for (int i = 0; i < m; i++) {
		int no1, no2;
		cin >> no1 >> no2;
		a[no1].push_back(no2);

	}
	f();

	cout << ans;
	return 0;
}