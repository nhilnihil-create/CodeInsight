#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int hoge(vector<int> vec) {
	int ret = 100;
	int pre = 0;
	for (int i = 0; i <= 24; ++i) {
		if (i == 24 && pre == 0) { continue; }
		if (vec[i] > 1) {
			ret = 0;
			break;
		}
		if (i > 0 && vec[i] == 1) {
			ret = min(ret, i - pre);
			pre = i;
		}
	}
	return ret;
}

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	for (int i = 0; i < N; ++i) { cin >> D[i]; }

	if (N > 23) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < (1<<N); ++i) {
		vector<int> vec(25, 0);
		vec[0] = vec[24] = 1;
		for (int j = 0; j < N; ++j) {
			if ((i>>j) & 1) { ++vec[D[j] % 24]; }
			else { ++vec[(24 - D[j]) % 24]; }
		}
		ans = max(ans, hoge(vec));
	}
	cout << ans << endl;

	return 0;
}
