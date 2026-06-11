#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N; long long X;
	cin >> N >> X;
	long long bound = X * N * 2;
	vector<long long> P(N), PS(N + 1);
	for (int i = N - 1; i >= 0; --i) cin >> P[i], bound += P[i] * 5;
	for (int i = 1; i <= N; ++i) PS[i] = PS[i - 1] + P[i - 1];
	long long ans = bound;
	for (int i = 1; i < N; ++i) {
		long long cost = X * (N + i);
		for (int j = 0; i * j < N; ++j) {
			cost += (PS[min(N, i * j + i)] - PS[i * j]) * (j == 0 ? 5 : 2 * j + 3);
			if (cost > ans) cost = ans;
		}
		ans = cost;
	}
	cout << ans << endl;
	return 0;
}