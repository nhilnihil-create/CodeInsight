#include <bits/stdc++.h>

using namespace std;

inline void Boost() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
typedef long long int ll;
typedef long double ld;

int main() {
	Boost();

	int n, z, w;
	cin >> n >> z >> w;

	vector < int > v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	int ans = abs(w - v[n - 1]);
	if (n > 1) {
		ans = max(ans, abs(v[n - 1] - v[n - 2]));
	}

	cout << ans;
	return 0;
}