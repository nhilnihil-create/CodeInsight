#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> t[1111];
long d[1111][11111];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> get<0>(t[i]) >> get<1>(t[i]) >> get<2>(t[i]);
	sort(t, t + n, [](auto a, auto b) {return get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b); });
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < 10002; j++) {
			int s = min(j > 10000 ? 10000 : j - get<0>(t[i]), get<1>(t[i]));
			d[i + 1][j] = max(d[i][j], (s < 0 ? 0 : d[i][s] + get<2>(t[i])));
		}
	}
	cout << d[n][10001] << endl;
	return 0;
}
