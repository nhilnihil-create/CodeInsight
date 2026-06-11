#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
using namespace std;

typedef long long ll;


int main() {
	ll n, a, b; cin >> n >> a >> b;
	if (a + b > n + 1 || a*b < n) {
		cout << -1 << endl;
		return 0;
	}
	if (b == 1) {
		if (a == n) for (ll i = 1; i <= n; i++) cout << i << (i < n ? " " : "\n");
		else cout << -1 << endl;
		return 0;
	}

	vector<ll> ans;
	for (ll i = n - a + 1; i <= n; i++) ans.push_back(i);
	ll pos = n - a;
	ll bl = (n - a) / (b - 1);
	ll res = (n - a) % (b - 1);
	for (ll i = 1; i <= b - 1; i++) {
		for (ll j = pos - bl - (i <= res) + 1; j <= pos; j++) ans.push_back(j);
		pos = pos - bl - (i <= res);
	}
	for (ll i = 0; i < n; i++) cout << ans[i] << (i < n - 1 ? " " : "\n");
	return 0;
}