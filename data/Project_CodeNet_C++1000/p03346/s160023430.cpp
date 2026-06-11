#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 41;
const int mod = 1e9 + 7;
const long long INF = 1e16;
const int inf = 1e9;

int dp[int(2e5) + 5];

int main () {
	boost;
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; ++ i) {
		int x;
		cin >> x;
		dp[x] = dp[x - 1] + 1;
	}
	cout << n - *max_element (dp, dp + n + 2);
}