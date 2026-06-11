#include <iostream>
#include <algorithm>
using namespace std;
int N; long long C, x[100009], v[100009], opt[100009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> v[i];
	}
	long long ret = 0;
	for (int i = 0; i < 2; i++) {
		long long rsum = 0;
		for (int j = N - 1; j >= 0; j--) {
			rsum += v[j];
			opt[j] = max(opt[j + 1], rsum - 2 * (C - x[j]));
		}
		ret = max(ret, opt[0]);
		long long sum = 0;
		for (int j = 0; j < N; j++) {
			sum += v[j];
			ret = max(ret, sum + opt[j + 1] - x[j]);
		}
		for (int j = 0; j < N; j++) x[j] = C - x[j];
		reverse(x, x + N);
		reverse(v, v + N);
	}
	cout << ret << "\n";
	return 0;
}