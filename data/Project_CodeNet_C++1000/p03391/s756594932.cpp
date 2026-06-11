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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vi a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	if (a == b) {
		cout << 0 << '\n';
		return 0;
	}

	ll ans = 0;
	vi beta;

	for (int i = 0; i < n; i++) {

		if (a[i] <= b[i]) {

			ans += b[i];
		}
		else {

			beta.pb(i);
		}
	}

	if (sz(beta) >= 2) {

		sort(all(beta), [&](int i, int j) { return b[i] > b[j]; });

		for (int i = 0; i < sz(beta) - 1; i++) {

			ans += b[beta[i]];
		}
	}

	cout << ans;
}
