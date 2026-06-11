#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, T, A;
	cin >> N >> T >> A;

	int ans = 0;
	double minval = (double)100000;
	for (int i = 0; i < N; ++i) {
		int H;
		cin >> H;

		double tmp = (double)T - H * 0.006;
		double dist = abs(A - tmp);
		if (dist < minval) {
			ans = i;
			minval = dist;
		}
	}
	cout << ans+1 << endl;
	return 0;
}
