#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int max_abs = 100001;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	vector<int> cl(max_abs * 2 + 1), cr(max_abs * 2 + 1);
	int N;
	cin >> N;
	long long sl = 0, sr = 0;
	for (int i = 0; i < N; ++i) {
		int L, R;
		cin >> L >> R;
		++cl[L + max_abs];
		++cr[R + max_abs];
		sr += L + max_abs;
	}
	++N;
	++cl[max_abs];
	++cr[max_abs];
	sr += max_abs;
	int pl = 0, pr = N;
	long long ret = (1LL << 62);
	for (int i = 0; i <= max_abs * 2; ++i) {
		pr -= cl[i];
		sr -= (long long)cl[i] * i;
		if (pl <= N / 2 && pr <= N / 2) {
			ret = min(ret, -2 * sl - 2LL * i * (N / 2 - pl) + 2LL * i * (N / 2 - pr) + 2 * sr);
		}
		pl += cr[i];
		sl += (long long)cr[i] * i;
	}
	cout << ret << '\n';
	return 0;
}