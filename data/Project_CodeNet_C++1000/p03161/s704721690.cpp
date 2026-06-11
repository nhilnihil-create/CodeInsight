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
const double PI = acos(-1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int64_t n, k;
	cin >> n >> k;
	vector<int64_t> arr(n);
	for(int64_t& el : arr) cin >> el;
	vector<int64_t> dp(n, int(1e18));
	dp[n-1] = 0;
	for(int i = n-2; i >= 0; i--) {
		for(int kk = 0; kk <= k; kk++) {
			if((i+kk) < n) dp[i] = min(dp[i], dp[i+kk] + abs(arr[i] - arr[i+kk]));
		}
	}
	cout << dp[0] << "\n";

	return 0;
}

