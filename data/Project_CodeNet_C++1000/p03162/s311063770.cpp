/*
	author: Ibrahim-Elsayed (Codeforces Handle)
	date: 9/17/2020
*/
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 1e5+20;

int n;
int64_t v[mxN+1][3];
int64_t dp[mxN+1][4];

int64_t go(int idx, int last) {
	if(idx == n) {
		if(last == 1) {
			return max(v[idx][1], v[idx][2]);
		} else if(last == 2) {
			return max(v[idx][0], v[idx][2]);
		} else {
			return max(v[idx][0], v[idx][1]);
		}
	}
	if(idx > n) {
		return (int64_t)-1e18;
	}
	if(dp[idx][last] != -1) {
		return dp[idx][last];
	}
	int64_t ans = (int64_t)-1e18;
	if(last != 1) {
		ans = max(ans, v[idx][0] + go(idx+1, 1));
	}
	if(last != 2) {
		ans = max(ans, v[idx][1] + go(idx+1, 2));
	}
	if(last != 3) {
		ans = max(ans, v[idx][2] + go(idx+1, 3));
	}
	//cout << ans << " ";
	return dp[idx][last] = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 4; j++) {
			dp[i][j] = -1;
		}
	}
	int64_t ans = go(1, 0);
	cout << ans << "\n";

	return 0;
}













