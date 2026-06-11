#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, p; cin >> n >> p;
	if (n == 1) {
		cout << p << endl;
		return 0;
	}
	vector<pair<int, long long>> v;
	double sq = sqrt(p);
	for (int i = 2; i <= sq; i++) {
		int cnt = 0;
		while (p % i == 0) {
			p /= i;
			cnt++;
		}
		if (cnt >= n) v.push_back(make_pair(i, cnt));
	}
	long long ans = 1;
	for (auto p : v) {
		long long m = p.second / n;
		for (int i = 0; i < m; i++) ans *= p.first;
	}
	cout << ans << endl;
}