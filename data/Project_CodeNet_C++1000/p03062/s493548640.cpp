#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	int n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<ll>>dp(n + 2, vector<ll>(2, 0));
	dp[0][0] = v[0];
	dp[0][1] = -v[0];
	for (int i = 0; i < n - 1; i++) {
		dp[i + 1][0] = max(dp[i][0] + v[i + 1], dp[i][1] - v[i + 1]);
		dp[i + 1][1] = max(dp[i][0] - v[i + 1], dp[i][1] + v[i + 1]);
	}
	cout << dp[n - 1][0] << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}