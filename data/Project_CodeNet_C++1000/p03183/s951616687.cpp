#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int dp[1000000];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	std::vector<int> w(n);
	std::vector<int> s(n);
	std::vector<int> v(n);
	std::vector<int> u(n);
	for (int i = 0; i < n; ++i) cin >> w[i] >> s[i] >> v[i], u[i] = i;
	sort(u.begin(), u.end(), [&](int a, int b){ return s[a] + w[a] < s[b] + w[b]; });
	for (int i = 0; i < n; ++i)
		for (int j = s[u[i]]; j >= 0; --j)
			dp[j + w[u[i]]] = max(dp[j + w[u[i]]], dp[j] + v[u[i]]);
	for (int i = 0; i <= 20000; ++i)
		dp[0] = max(dp[0], dp[i]);
	cout << dp[0];
}