#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> arr;
typedef vector<arr> matrix;
typedef vector<ll> longarr;
typedef vector<longarr> longmat;
typedef map<int, arr> graph;
typedef vector<char> chararr;
typedef vector<chararr> charmat;
typedef pair<int, int> fraction;
ll MOD = 1000000007;
int n, k;
ll a[100];
ll dp[101][100001];

ll fun() {
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]);
			if (a[i - 1] < j) dp[i][j] = (MOD + dp[i][j] - dp[i - 1][j - a[i - 1] - 1]) % MOD;
			else dp[i][j] = (dp[i][j] ) % MOD;
		}
	}
	return dp[n][k];
}
int main() {

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(dp, 0, sizeof(dp));
	cout << fun();

}