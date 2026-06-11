#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> ans;
	if (n % 2) {
		for (ll i = 1; i < n; ++i) {
			for (ll j = i + 1; j < n; ++j) {
				if (i + j == n)continue;
				ans.push_back({ i,j });
			}
		}
		for (ll i = 1; i < n; ++i) {
			ans.push_back({ i,n });
		}
	}
	else {
		for (ll i = 1; i <= n; ++i) {
			for (ll j = i + 1; j <= n; ++j) {
				if (i + j == n + 1)continue;
				ans.push_back({ i,j });
			}
		}
	}
	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}
}
