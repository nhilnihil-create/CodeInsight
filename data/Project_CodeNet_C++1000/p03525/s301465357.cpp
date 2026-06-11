#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int hoge(vector<int> vec) {
	int ret = 12;
	int n = vec.size();
	for (int i = 0; i < n; ++i) {
	   for (int j = i + 1; j < n; ++j) {
		   int diff = abs(vec[i] - vec[j]);
		   ret = min({ ret, diff, 24 - diff });
	   }
	}
	return ret;
}

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	for (int i = 0; i < N; ++i) { cin >> D[i]; }

	vector<int> cnt(13, 0);
	for (int i = 0; i < N; ++i) { ++cnt[D[i]]; }
	if (cnt[0] > 0 || cnt[12] > 1 || *max_element(cnt.begin(), cnt.end()) > 2) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> d1, d2;
	for (int i = 1; i < 12; ++i) {
		if (cnt[i] == 2) {
			d1.push_back(i);
			d1.push_back(24 - i);
		}
		if (cnt[i] == 1) { d2.push_back(i); }
	}
	d1.push_back(0);
	if (cnt[12] == 1) { d1.push_back(12); }
	int m = d2.size();

	int ans = 0;
	for (int i = 0; i < (1<<m); ++i) {
		vector<int> vec(d1);
		for (int j = 0; j < m; ++j) {
			if ((i>>j) & 1) { vec.push_back(d2[j]); }
			else { vec.push_back(24 - d2[j]); }
		}
		ans = max(ans, hoge(vec));
	}
	cout << ans << endl;

	return 0;
}
