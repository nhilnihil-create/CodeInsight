#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> gr[100005];
int dp[100005];
int longPath(int i) {
	if (dp[i] != -1)
		return dp[i];
	int sub = 0;
	for (auto child : gr[i])
		sub = max(sub, longPath(child) + 1);
	return dp[i] = sub;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		gr[x].push_back(y);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, longPath(i));
	}
	cout << ans;


	return 0;
}