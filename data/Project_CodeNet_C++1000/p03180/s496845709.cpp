#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vi> a(n, vi(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<ll> b(1 << n, 0);
	for (int m = 1; m < (1 << n); m++) {
		for (int i = 0; i < n; i++) {
			if (m >> i & 1) {
				for (int j = i + 1; j < n; j++) {
					if (m >> j & 1) {
						b[m] += a[i][j];
					}
				}
			}
		}
	}
	const ll inf = 1e18 + 228;
	vector<ll> dp(1 << n, -inf);
	dp[0] = 0;
	for (int m = 1; m < (1 << n); m++) {
		dp[m] = b[m];
		for (int g = (m - 1) & m; g > 0; g = (g - 1) & m) {
			dp[m] = max(dp[m], b[g] + dp[m ^ g]);
		}
	}
	cout << dp.back();
}
