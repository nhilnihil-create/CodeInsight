#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void max_self(ll& a, ll b) {
	a = max(a, b);
}

int main() {
	int n;
	cin >> n;
	int base = 1;
	while (base <= n) {
		base *= 2;
	}
	vector<ll> tree(base * 2), dp(n + 1);
	vector<int> height(n), weight(n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> height[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> weight[i];
	}
	for (int flower = 0; flower < n; ++flower) {
		ll best = 0;
		ll x = height[flower] + base;
		while (x > 1) {
			if (x % 2 == 1) {
				max_self(best, tree[x - 1]);
			}
			x /= 2;
		}

		dp[height[flower]] = weight[flower] + best;

		for (int i = height[flower] + base; i >= 1; i /= 2) {
		    max_self(tree[i], dp[height[flower]]);
		}
	}
	for (auto each : dp) {
		max_self(ans, each);
	}
	cout << ans << endl;
}
