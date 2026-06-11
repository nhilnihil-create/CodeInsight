#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
//#include <intrin.h>
//#include <chrono>
//#include <random>
//#include <unordered_map>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first.first >> a[i].first.second >> a[i].second;

	sort(a.begin(), a.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.first.first + a.first.second < b.first.first + b.first.second;
	});

	vector<ll> dp(20001, -1);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 20000; j >= 0; j--) {
			if (dp[j] == -1)
				continue;
			if (a[i].first.second >= j) {
				dp[j + a[i].first.first] = max(dp[j + a[i].first.first], dp[j] + a[i].second);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		//cout << '\n';
	}
}