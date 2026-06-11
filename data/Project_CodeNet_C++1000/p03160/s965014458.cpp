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

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int& el : arr) cin >> el;
	vector<int64_t> dp(n); // dp[i] is minimum total cost to reach the end starting from idx i;
	dp[n - 1] = 0;
	for(int i = n-2; i >= 0; i--) {
		dp[i] = dp[i + 1] + abs(arr[i] - arr[i+1]);
		if(i+2 < n) {
			dp[i] = min(dp[i], dp[i + 2] + abs(arr[i] - arr[i+2]));
		}
	}
	cout << dp[0];

	return 0;
}

